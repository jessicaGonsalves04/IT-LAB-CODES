#!/bin/bash

# Declare an array
declare -a arr
x=0

# Read each argument into the array
for num in "$@"; do
    arr[((x++))]=$num
done

# Get the total number of arguments
n=$#
echo "Total words: $n"

# Sort the array
for ((i = 0; i < n - 1; i++)); do
    for ((j = 0; j < n - 1 - i; j++)); do
        if [[ ${arr[$j]} > ${arr[$j + 1]} ]]; then
            # Swap elements
            temp=${arr[$j]}
            arr[$j]=${arr[$j + 1]}
            arr[$j + 1]=$temp
        fi
    done
done

# Print the sorted list
echo "The sorted list is: "
x=1
for i in "${arr[@]}"; do
    echo "$x) $i"
    ((x++))
done

