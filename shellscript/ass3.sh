#!/bin/bash

is_pal(){
	local x="$1"

	rev=$(echo "$x" | rev)
	
	if (( $x == $rev )); then
		return 0;
	else
		return 1;
	fi
}

for num in "$@"; do
	if is_pal "$num"; then
		echo " $num is palindrome" 
	fi
done
		

