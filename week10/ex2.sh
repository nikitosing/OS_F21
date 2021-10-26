echo "Nikita Pozdniakov" > ../week01/file.txt
link ../week01/file.txt _ex2.txt
ls -i _ex2.txt
ls -i ../week01/file.txt
find ../week01/file.txt -inum 152616
find ../week01/file.txt -inum 152616 -exec rm {} \;
find ../week01/file.txt -inum 152616
