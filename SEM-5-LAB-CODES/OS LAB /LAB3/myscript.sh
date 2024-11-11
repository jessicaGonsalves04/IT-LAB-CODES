#!/bin/bash

# Prompt user for the directory and pattern
read -p "Enter the directory path: " directory
read -p "Enter the pattern to search for: " pattern

# Check if the directory exists
if [ -d "$directory" ]; then
  # List files containing the pattern
  grep -rli "$pattern" "$directory"
else
  echo "The directory does not exist."
fi

