#!/bin/bash

# System defaults, change these if needed
DEFAULT_VITIS_DIR="/tools/Xilinx/Vitis/2024.2"
#SYSROOT="/home/tls/xilinx/sysroots/xilinx-zynqmp-common-v2024.2/sysroots/cortexa72-cortexa53-xilinx-linux"
SYSROOT="/home/tls/xilinx/sysroots/kria-ubuntu-24.04/sysroot"
#PLATFORM="xilinx_zcu102_base_202420_1"
PLATFORM="/home/tls/xilinx/platforms/xilinx_kv260_bist_202410_1/kv260_bist.xpfm"
FREQ="300MHz"

# App specific variables, change these if needed
APP_NAME="edge_detect"
HOST_CODE="edge_detect.cpp"
KERNEL_CODE="cluster0.cpp"
BRIDGE_CODE="cluster0_bridge.cpp"
TOP_FUNCTION="cluster0"
BUILD_DIR="build"

# Step 1: verify environment
echo "Verifying environment..."

# Step 1.1: Check if XILINX_VITIS is defined; if not, try to source settings64.sh
if [ -z "$XILINX_VITIS" ]; then
  XILINX_DIR="${1:-$DEFAULT_VITIS_DIR}"
  SETTINGS_FILE="$XILINX_DIR/settings64.sh"
  if [ -f "$SETTINGS_FILE" ]; then
    # shellcheck disable=SC1090
    source "$SETTINGS_FILE"
    echo "Sourced $SETTINGS_FILE"
  else
    echo "Error: $SETTINGS_FILE not found, please set XILINX_VITIS or change the script to point to the correct location."
    exit 1
  fi
else
  echo "XILINX_VITIS already set to $XILINX_VITIS"
fi

# Step 1.2: Check if v++ is operational
if ! command -v v++ >/dev/null 2>&1; then
  echo "Error: v++ command not found even after sourcing environment."
  exit 1
fi
echo "v++ is available."

# Step 1.3: Verify that ARM compiler is available
ARM_COMP=$XILINX_VITIS/gnu/aarch64/lin/aarch64-linux/bin/aarch64-linux-gnu-g++
if [ ! -f "$ARM_COMP" ]; then
  echo "Error: ARM compiler not found at $ARM_COMP, change this script to point to the correct location."
  exit 1
fi
echo "ARM compiler found at $ARM_COMP"

# Step 1.4: Verify that sysroot is available
if [ ! -d "$SYSROOT" ]; then
  echo "Error: Sysroot directory $SYSROOT does not exist, change this script to point to the correct location."
  exit 1
fi
echo "Sysroot directory verified: $SYSROOT"

# Step 1.5: create build directory, or empty it if it exists
if [ -d "$BUILD_DIR" ]; then
  echo "Build directory $BUILD_DIR exists, emptying it..."
  rm -rf "$BUILD_DIR"/*
else
  echo "Creating build directory $BUILD_DIR..."
  mkdir -p "$BUILD_DIR"
fi

# Step 2: Compile SW-only version
echo "Compiling SW-only version..."
$ARM_COMP $HOST_CODE -O3 -o "${BUILD_DIR}/${APP_NAME}_sw.elf" -lm
echo "SW-only version compiled successfully."

# Step 3: Compile SW-HW version
echo "Compiling SW-HW version..."

# Step 3.1: Compile the host
echo "Compiling host code..."
HOST_FLAGS="-O3 -DOFFLOAD -fno-lto"
CPP_INCLUDES="-I$SYSROOT/usr/include/c++/13 \
                -I$SYSROOT/usr/include/c++/13 \
                -I$SYSROOT/usr/include/aarch64-linux-gnu/c++/13 \
                -I$SYSROOT/usr/include/c++/13/backward \
                -I$SYSROOT/usr/lib/gcc/aarch64-linux-gnu/13/include \
                -I$SYSROOT/usr/local/include \
                -I$SYSROOT/usr/include/aarch64-linux-gnu \
                -I$SYSROOT/usr/include"
XRT_INCLUDES="-I$SYSROOT/usr/include/xrt"

STARTUP_FILES="-B$SYSROOT/usr/lib/aarch64-linux-gnu \
                -B$SYSROOT/usr/lib/gcc/aarch64-linux-gnu/13"

LIBS_PATH="-L$SYSROOT/lib \
            -L$SYSROOT/usr/lib \
            -L$SYSROOT/usr/lib/aarch64-linux-gnu \
            -L$SYSROOT/usr/local/lib \
            -L$SYSROOT/usr/local/lib/aarch64-linux-gnu"
LIBS_LINK="-lxrt++ -lxrt_core -lxrt_coreutil -lm -luuid"
COMPILER_PATH=$SYSROOT/usr/libexec/gcc/aarch64-linux-gnu/13

$ARM_COMP $HOST_CODE $BRIDGE_CODE --sysroot=$SYSROOT $HOST_FLAGS -o "${BUILD_DIR}/${APP_NAME}_host.elf" $CPP_INCLUDES $XRT_INCLUDES $STARTUP_FILES $LIBS_PATH $LIBS_LINK
echo "Host code compiled successfully."

# Step 3.2: Compile the kernel
echo "Compiling kernel code..."
mkdir -p ./kernel_synthesis
cd ./kernel_synthesis
v++ -c -t hw --platform $PLATFORM -k $TOP_FUNCTION -I . -o "../${BUILD_DIR}/${TOP_FUNCTION}.xo" ../$KERNEL_CODE --temp_dir syn --kernel_frequency $FREQ
mv ../${BUILD_DIR}/${TOP_FUNCTION}.xo.compile_summary .
cd ..
echo "Kernel code compiled successfully."

# Step 3.3: Link the host and kernel
echo "Linking host and kernel..."
mkdir -p ./kernel_linking
cd ./kernel_linking
v++ -l -t hw --platform $PLATFORM -o "../${BUILD_DIR}/${TOP_FUNCTION}.xclbin" "../${BUILD_DIR}/${TOP_FUNCTION}.xo" --temp_dir ./link
mv ../${BUILD_DIR}/${TOP_FUNCTION}.xclbin.link_summary .
mv ../${BUILD_DIR}/${TOP_FUNCTION}.xclbin.info .
rm ../${BUILD_DIR}/${TOP_FUNCTION}.xo
cd ..
echo "SW-HW version compiled successfully."