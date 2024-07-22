# system dependent
PETALINUX_PATH=/tools/Xilinx/PetaLinux
ZCU102_XSA_PATH=/tools/Xilinx/Vitis/2024.1/base_platforms/xilinx_zcu102_base_202410_1/hw/hw.xsa

NAME=ZCU102
echo "Removing old project"
rm -rf $NAME
source $PETALINUX_PATH/settings.sh
PETALINUX_SCRIPTS=$PETALINUX_PATH/scripts


$PETALINUX_SCRIPTS/petalinux-create -t project -n $NAME --template zynqMP

# A menu will show up for configuration, use below config to avoid password for login.
#       menu -> "Yocto Setting" -> "Enable Debug Tweaks"
$PETALINUX_SCRIPTS/petalinux-config -p $NAME --get-hw-description=$ZCU102_XSA_PATH

$PETALINUX_SCRIPTS/petalinux-config -p $NAME -c kernel

#   menu -> "user packages" -> xrt
#   menu -> "user packages" -> xrt-dev
#   menu -> "user packages" -> zocl
#   menu -> "user packages" -> opencl-headers-dev
#   menu -> "user packages" -> opencl-clhpp-dev
$PETALINUX_SCRIPTS/petalinux-config -p $NAME -c rootfs

# Build package
$PETALINUX_SCRIPTS/petalinux-build -p $NAME 