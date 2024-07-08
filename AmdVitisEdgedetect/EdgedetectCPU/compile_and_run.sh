#!/bin/bash

[ -f "output.bmp" ] && rm "output.bmp"
g++ *.cpp
./a.out
rm a.out