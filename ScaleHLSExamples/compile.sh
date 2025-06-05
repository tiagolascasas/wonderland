#!/bin/bash
DEFAULT_CXX_PATH=/edgedetect/edge_detect.c
DEFAULT_TOP_FUNCTION=rgbToGrayscale
DEFAULT_SCALEHLS_DIR=~/dev/scalehls

CXX_PATH="${1:-DEFAULT_CXX_PATH}"
TOP_FUNCTION="${2:-$DEFAULT_TOP_FUNCTION}"
SCALEHLS_DIR="${3:-$DEFAULT_SCALEHLS_DIR}"

CXX_SOURCE=$(basename $CXX_PATH)
CXX_EXT=$(echo "${CXX_SOURCE##*.}")

if [[ $CXX_SOURCE == *.c ]]; then
    MLIR_OUTPUT="${CXX_SOURCE%.c}.mlir"
elif [[ $CXX_SOURCE == *.cpp ]]; then
    MLIR_OUTPUT="${CXX_SOURCE%.cpp}.mlir"
else
    echo "Error: $CXX_SOURCE is not a .c or .cpp file"
    exit 1
fi
OUTDIR=output/${CXX_SOURCE%.*}_$CXX_EXT

rm -rf $OUTDIR
mkdir -p $OUTDIR
cp $CXX_PATH $OUTDIR
cp config.json $OUTDIR
cd $OUTDIR

export PATH=$PATH:$SCALEHLS_DIR/build/bin:$SCALEHLS_DIR/polygeist/build/bin

cgeist $CXX_SOURCE -function=$TOP_FUNCTION -S -memref-fullrank -raise-scf-to-affine -resource-dir=$(clang -print-resource-dir) > $MLIR_OUTPUT
scalehls-opt $MLIR_OUTPUT -debug-only=scalehls -scalehls-dse-pipeline="top-func=$TOP_FUNCTION target-spec=config.json" \
| scalehls-translate -scalehls-emit-hlscpp > $CXX_SOURCE
