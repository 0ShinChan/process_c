#!/bin/bash

if [ ! -f "numbers.txt" ]; then
	echo " Invalid file"
else 
	echo " Proceeding..."
fi

a=$(head -n 1 numbers.txt)
b=$(head -n 1 numbers.txt)

while IFS= read -r number; do 
	if [[ "$number" -gt "$a" ]]; then
		a="$number"
	fi
	if [[ "$number" -lt "$b" ]]; then
		b="$number"
	fi
done < numbers.txt

echo "big $a"
echo "small $b"
