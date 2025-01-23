#!/bin/bash

read -p " Enter the lenth fo fiboncci series: " n

a=0
b=1

touch output.txt

echo "0" > output.txt
echo "1" >> output.txt

for ((i=2; i<=$n; i++)); do 
	c=$((a + b))
	echo "$c" >> output.txt

	a=$b
	b=$c
done

echo "done"

