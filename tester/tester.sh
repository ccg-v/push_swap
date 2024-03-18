#!/bin/bash
# Set 'MAX' with the amount of numbers to be sorted
# To run: ./tester.sh

MAX=25
NUMS=$(ruby -e "puts (1..${MAX}).to_a.shuffle.join(' ')")

echo "Generated sequence: $NUMS"
./push_swap $NUMS | wc -l
