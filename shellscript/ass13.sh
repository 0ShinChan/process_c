#!/bin/bash


process=$(ps -e | awk '{ if($8 == "S") print $1}')

if [ -z "$process" ]; then
	echo " no process is sleeping " 
else 
	echo "$process is sleeping"
fi

