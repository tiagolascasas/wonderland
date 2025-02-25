source ../set_env.sh
sudo fpgautil -b spamfilter.bin
echo "Running rosetta-spam-filter-printf"
time ./spamfilter-p