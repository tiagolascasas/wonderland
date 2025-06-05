#!/bin/bash

# Defaults, change these if needed
DEFAULT_VITIS_DIR="/tools/Xilinx/Vitis/2024.2"
SYSROOT="/home/tls/xilinx/sysroots/xilinx-zynqmp-common-v2024.2/sysroots/cortexa72-cortexa53-xilinx-linux"

APP_NAME="edge_detect"
HOST_CODE="edge_detect.cpp"
KERNEL_CODE="cluster0.cpp"
BRIDGE_CODE="cluster0_bridge.cpp"

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

# Step 2: Compile SW-only version
echo "Compiling SW-only version..."
$ARM_COMP $HOST_CODE -O3 -o "${APP_NAME}_sw.elf" -lm
echo "SW-only version compiled successfully."

# Step 3: Compile SW-HW version
echo "Compiling SW-HW version..."

# Step 3.1: Compile the host
echo "Compiling host code..."
ARM_INCLUDES="$SYSROOT/usr/include/"
XRT_INCLUDES="$SYSROOT/usr/include/xrt"
XRT_LIBS="$SYSROOT/usr/lib/xrt"

$ARM_COMP $HOST_CODE $BRIDGE_CODE -O3 -o "${APP_NAME}_host.elf" -lm -DOFFLOAD -I$ARM_INCLUDES -I$XRT_INCLUDES -I$XILINX_VITIS/include -L$XRT_LIBS -lxrt_coreutil -lxrt_host -luuid
echo "Host code compiled successfully."
