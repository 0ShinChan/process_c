#!/bin/bash
set -x
update_marks(){
	local roll_no="$1"
	local new_marks="$2"
	local temp="temp.txt"

	touch "$temp"

	while IFS= read -r line; do 
		ro=$(echo "$line" | cut -d' ' -f1)
		if [[ "$ro" == "$roll_no" ]]; then
			name=$(echo "$line" | cut -d' ' -f2)
			echo "$ro $name $new_marks" >> "$temp"
		else
			echo "$line" >> "$temp"
		fi
	done < students.txt

	mv "$temp" "students.txt"
}

read -p "Enter the  roll no of the student " roll
read -p " Enter the updated marsk of the student" marks
update_marks "$roll" "$marks"
echo " updated "
