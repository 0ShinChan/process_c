#!/bin/bash

# Get input value for x
read -p "Enter the value of x: " x

# Initialize variables
sum=1
term=1
power=2

# Calculate series up to 10 terms (adjust as needed)
for ((i=1; i<=4; i++)); do
  # Calculate current term
  current_term=$(echo "scale=10; ($x/2)^$power * $term" | bc)

  # Add current term to sum
  sum=$(echo "scale=10; $sum + $current_term" | bc)

  # Update power and term for next iteration
  power=$((power + 1))
  term=$((term * -1)) 
done

# Print the result
echo "Sum of the series: $sum"


