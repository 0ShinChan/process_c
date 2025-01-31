#!/bin/bash

read -p "Enter a number" num

case "$((num % 2))" in 
	0)
		echo "even"
		;;
	*)
		echo "odd"
		;;
esac
