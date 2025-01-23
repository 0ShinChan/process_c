#!/bin/bash

is_pal() {
	local word="$1"
	local revw=$(echo "$word" | rev)

	local c_word="${word//[.,;]/}"
	local c_rev="${revw//[.,;]/}"

	if [[ "$c_word" == "$c_rev" ]]; then
		echo "$c_word"
	fi
}

while IFS= read -r word; do
	is_pal "$word"
done < input.txt


	
