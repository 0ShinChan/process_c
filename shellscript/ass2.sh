#!/bin/bash

read -p "enter a value for x: " x
read -p "enter the length of term: " n
sum=1
val=$(echo "scale=3; $x / 2 " | bc)

for ((i=2;i<=n;i++)); do
	term=$(echo "scale=3; $val^$i " | bc)

	if (( i % 2 == 0)); then
		sum=$(echo "scale=3; $sum + $term " | bc)
	else 
		sum=$(echo " scale=3; $sum - $term" | bc)
	fi
done

echo "ans: $sum"
