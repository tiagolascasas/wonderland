# system dependent
PETALINUX_PATH=/tools/Xilinx/PetaLinux
ZCU102_XSA_PATH=/tools/Xilinx/Vitis/2024.1/base_platforms/xilinx_zcu102_base_202410_1/hw/hw.xsa

rm -rf ZCU102
source $PETALINUX_PATH/settings.sh
PETALINUX_SCRIPTS=$PETALINUX_PATH/scripts
$PETALINUX_SCRIPTS/petalinux-create --type project --template zynqMP --name ZCU102
cd ZCU102
$PETALINUX_SCRIPTS/petalinux-config --get-hw-description=$ZCU102_XSA_PATH --silentconfig
$PETALINUX_SCRIPTS/petalinux-build -c xrt
petalinux-package boot --fsbl images/linux/zynqmp_fsbl.elf --fpga $ZCU102_XSA_PATH --u-boot