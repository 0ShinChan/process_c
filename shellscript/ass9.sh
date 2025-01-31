#!/bin/bash

read -p "Enter the directory: " drc

if [ ! -d "$drc" ]; then
	echo " $drc is not a valid directory"
	exit 1
fi

file_count=$(find "$drc" -maxdepth 1 -type f | wc -l)
file_list=$(ls -1 "$drc")

#file_list=$(find "$drc" -maxdepth 1 -type f)

touch out.txt

echo " directory $drc" > out.txt

echo " count: $file_count" >> out.txt

echo " $file_list" >> out.txt

cat out.txt

