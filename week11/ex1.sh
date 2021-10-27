sudo losetup -f lofs.img
sudo mkfs.ext4 $(losetup -a | grep 'lofs.img' | awk '{print $1}' | cut -d ':' -f 1)
sudo mount $(losetup -a | grep 'lofs.img' | awk '{print $1}' | cut -d ':' -f 1) ./lofsdisk
cd lofsdisk