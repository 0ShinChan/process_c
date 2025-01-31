#!/bin/bash

d=$(date +"%d/%m/%y")
m=$(echo "$d" | cut -d/ -f2)
echo "$m"

