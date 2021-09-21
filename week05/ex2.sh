#!/bin/bash

file="ex2.txt"
lock_file="${file}.lock"
while :
do
if [ ! -f $file ]
then
  echo 0 > $file
fi

while [ -f $lock_file ]
do
  :
done

echo "locked" > $lock_file

count=$(tail -n 1 $file)
((count=count+1))
echo $count >> $file

rm $lock_file
done 
