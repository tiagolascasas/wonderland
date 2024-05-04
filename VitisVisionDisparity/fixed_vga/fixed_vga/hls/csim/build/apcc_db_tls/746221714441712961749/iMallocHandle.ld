#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/tls/Dev/wonderland/VitisVisionDisparity/fixed_vga/fixed_vga/hls/csim/build/apcc_db_tls/746221714441712961749/iMallocHandle.ld.bc ${1+"$@"}
