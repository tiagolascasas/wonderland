mkdir -p bin-generic
cd src-generic
g++ *.cpp -o ../bin-generic/edge_def.elf -D SIZE=DEFAULT
g++ *.cpp -o ../bin-generic/edge_sd.elf -D SIZE=SD
g++ *.cpp -o ../bin-generic/edge_hd.elf -D SIZE=HD
g++ *.cpp -o ../bin-generic/edge_2k.elf -D SIZE=_2K
g++ *.cpp -o ../bin-generic/edge_qhd.elf -D SIZE=QHD
g++ *.cpp -o ../bin-generic/edge_4k.elf -D SIZE=_4K

cd ../bin-generic
./edge_def.elf
./edge_sd.elf
./edge_hd.elf
./edge_2k.elf
./edge_qhd.elf
./edge_4k.elf

python ../../ImageToArray/imgToArray.py -i output_img_512_512.dat 512 512 g
python ../../ImageToArray/imgToArray.py -i output_img_640_480.dat 640 480 g
python ../../ImageToArray/imgToArray.py -i output_img_1280_720.dat 1280 720 g
python ../../ImageToArray/imgToArray.py -i output_img_1920_1080.dat 1920 1080 g
python ../../ImageToArray/imgToArray.py -i output_img_2560_1440.dat 2560 1440 g
python ../../ImageToArray/imgToArray.py -i output_img_3840_2160.dat 3840 2160 g
