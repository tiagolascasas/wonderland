source ../set_env.sh
sudo fpgautil -b reverse_print.bin
echo "Running reverse_print"
time ./reverse_print-p