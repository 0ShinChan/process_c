#!/bin/bash
set -x
read -p "Enter student's marks: " marks

if [[ "$marks" -ge 0 && "$marks" -le 100 ]]; then
  case "$marks" in
    [90-100])
      grade="A+"
      ;;
    [80-89])
      grade="A"
      ;;
    [70-79])
      grade="B"
      ;;
    [60-69])
      grade="C"
      ;;
    [50-59])
      grade="D"
      ;;
    [0-49])
      grade="F"
      ;;
  esac
  echo "Grade: $grade"
else
  echo "Invalid marks. Please enter marks between 0 and 100."
fi
