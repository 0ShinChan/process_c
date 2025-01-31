#!/bin/bash

# Assuming the input file is named "students.txt" and 
# each line has the format: "Roll No. Name Marks"

# Find the student with the highest marks
highest_marks=$(awk '{if ($3 > max) {max=$3; top_roll=$1; top_name=$2}} END {print top_roll, top_name, max}' students.txt)

# Extract roll number, name, and marks
top_roll=$(echo "$highest_marks" | awk '{print $1}')
top_name=$(echo "$highest_marks" | awk '{print $2}')
top_marks=$(echo "$highest_marks" | awk '{print $3}')

# Print the result
echo "Student with the highest marks:"
echo "Roll No.: $top_roll"
echo "Name: $top_name"
echo "Marks: $top_marks"
