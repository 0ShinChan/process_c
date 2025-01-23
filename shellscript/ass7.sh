#!/bin/bash

file_count() {

	local file="$1"

	local ch=$(wc -m < "$file" | awk '{print $1}')
	
	 local word=$(wc -w < "$file" | awk '{print $1}')

	 local line=$(wc -l < "$file" | awk '{print $1}')

	 echo " filename: $file"
	 echo " letters : $ch"
	 echo " words : $word"
	 echo " line : $line"
	 echo "-----------------------------------------"

}

for file in "$@"; do
	file_count "$file"
done


	
