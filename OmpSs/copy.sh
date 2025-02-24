DEST=/media/tls/root/home/ompss/
sudo rm -rf $DEST/builds
sudo cp -r builds $DEST
sudo tree $DEST/builds -L 2