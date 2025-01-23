#!/bin/bash

is_arm() {

	local n="$1"
	local d=$(echo "${#n}")

	local temp=$n
	local sum=0
	while [ "$temp" -gt 0 ]; do
		digit=$((temp % 10))
		sum=$(( sum + (digit ** d)))
		temp=$((temp / 10))
	done

	if [ "$sum" ==  "$n" ]; then
		echo "$n is armstrong"
	fi
}

for num in "$@"; do 
	is_arm "$num"
done
	
