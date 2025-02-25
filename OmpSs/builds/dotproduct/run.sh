source ../set_env.sh
sudo fpgautil -b dotproduct.bin
echo "Running dotproduct"
time ./dotproduct-p