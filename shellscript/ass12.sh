#!/bin/bash
for year in "$@"; do
	if (( ((year % 4 == 0) && (year % 100 != 100)) || (year % 400 == 0) )); then
		echo "$year is leapyear"
	fi
done


		
