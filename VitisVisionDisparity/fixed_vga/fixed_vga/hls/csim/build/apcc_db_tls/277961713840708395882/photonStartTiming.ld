#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/tls/Dev/wonderland/VitisVisionDisparity/fixed_vga/fixed_vga/hls/csim/build/apcc_db_tls/277961713840708395882/photonStartTiming.ld.bc ${1+"$@"}
