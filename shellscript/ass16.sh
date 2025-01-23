#!/bin/bash

is_leap() {
	local yy=$1
	   if [ $((yy % 4)) -eq 0 ] && [ $((yy % 100)) -ne 0 ] || [ $((yy % 400)) -eq 0 ]; then
		 return 0
	else 
		return 1
	fi
}

is_date() {
	local year=$(echo "$1" | cut -d/ -f1)
	local month=$(echo "$1" | cut -d/ -f2)
	local day=$(echo "$1" | cut -d/ -f3)
	
	if [ ($month -gt 1) && ( $month -lt 12) ]; then
		return 0
	fi

	case "$month" in 
	2)
		if [[ is_leap "$year"  && $day -gt 29 ]]; then
			return 1
		elif [[ ! is_leap "$year" && $day -gt 28 ]]; then
			return 1
		fi
		;;
	4|6|9|11)
		if [[ $day -gt 30 ]]; then
			return 1
		fi
		;;

	*) 
		if [[ $day -gt 31 ]]; then
			return 1
		fi
		;;
	esac

	return 0
}



	

read -p " Enter the date in dd/mm/yyyy format: " date

if is_date "$date"; then
	echo " valid "
else 
	echo " Invalid"
fi


