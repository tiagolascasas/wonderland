#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/tls/Dev/wonderland/VitisVisionDisparity/fixed_vga/fixed_vga/hls/csim/build/apcc_db_tls/744991714441708798562/getDisparity.ld.bc ${1+"$@"}
