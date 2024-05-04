#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/tls/Dev/wonderland/VitisVisionDisparity/fixed_vga/fixed_vga/hls/csim/build/apcc_db_tls/741361714441698100387/fMallocHandle.ld.bc ${1+"$@"}
