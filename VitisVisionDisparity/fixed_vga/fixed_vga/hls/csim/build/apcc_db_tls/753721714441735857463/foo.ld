#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/tls/Dev/wonderland/VitisVisionDisparity/fixed_vga/fixed_vga/hls/csim/build/apcc_db_tls/753721714441735857463/foo.ld.bc ${1+"$@"}
