#!/bin/bash

echo "Compiling the bitstream for the ZCU102 board..."
#make bitstream-p BOARD=zcu102

echo "Compiling executable for the ZCU102 board..."
export CROSS_COMPILE=aarch64-linux-gnu-
make dotproduct-p dotproduct-d dotproduct-i