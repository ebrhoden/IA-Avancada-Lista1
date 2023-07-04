#!/bin/bash

# Remove the old 15puzzle_instances.csv file if it exists
rm -f 15puzzle_instances.csv

# Read the file line by line
while IFS= read -r line
do
  # Run the main program with -astar argument and the line as input
  # Limit the execution time to 30 seconds
  # Append the output to 15puzzle_instances.csv
  if ! gtimeout 300s ./main -astar $line >> 15puzzle_instances.csv
  then
    # If the command times out, append -,-,-,-,- to the csv file
    echo "-,-,-,-,-" >> 15puzzle_instances.csv
  fi
done < "15puzzle_instances.txt"