#!/bin/bash
# Set 'MAX' with the amount of numbers to be sorted
# To run: ./tester.sh

MAX=25
NUMS=$(shuf -i 1-$MAX | tr '\n' ' ')

echo "Generated sequence: $NUMS"
echo -n "Total movements: "
./push_swap $NUMS | wc -l
