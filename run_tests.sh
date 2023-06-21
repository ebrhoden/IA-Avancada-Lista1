#!/bin/bash

# Remove the old test1.csv file if it exists
rm -f test1.csv

# Read the file line by line
while IFS= read -r line
do
  # Run the main program with -astar argument and the line as input
  # Limit the execution time to 30 seconds
  # Append the output to test1.csv
  gtimeout 30s ./main -astar $line >> test1.csv
done < "15puzzle_instances.txt"