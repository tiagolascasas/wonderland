source ../set_env.sh
sudo fpgautil -b reverse_sort.bin
echo "Running reverse_sort"
time ./reverse_sort-p