rm *.bmp
gcc src/*.c -lm -o bin/edgedetect.elf -D OUTS
./bin/edgedetect.elf
python ../ImageToArray/imgToArray.py -i input.dat 512 512 rgb
python ../ImageToArray/imgToArray.py -i grayscale.dat 512 512 g
python ../ImageToArray/imgToArray.py -i conv1.dat 512 512 g
python ../ImageToArray/imgToArray.py -i conv2.dat 512 512 g
python ../ImageToArray/imgToArray.py -i conv3.dat 512 512 g
python ../ImageToArray/imgToArray.py -i output.dat 512 512 g
rm *.dat