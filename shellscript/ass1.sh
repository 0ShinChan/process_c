#!/bin/bash


factorial() {
	local n=$1
	local fact=1

	if [ $n -eq 0 ]; then
		echo $fact
	else 
		for ((i=1;i<=$n;i++)); do 
			fact=$((fact*i))
		done
		echo $fact
	fi
}


read -p "Enter the value of x" x

read -p "Enter the function length" n

sum=0

for ((i=0;i<=$n;i++)); do
	deno=$(factorial $((i*2)))
	term=$(echo "scale=3; $x^$((i*2)) / $deno" | bc)
	sum=$(echo "scale=3; $sum + $term" | bc)

done

echo "ans: $sum"

