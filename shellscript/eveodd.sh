#!/bin/bash

# Loop through numbers from 1 to 10
for ((i=1; i<=10; i++)); do
  # Check if the number is odd
  if (( $i % 2 != 0 )); then
    echo $i
  fi
done

