#!/bin/bash
paste your_steps.txt their_steps.txt | awk -F'\t' '
{
    print "Index " NR ": YOUR=" $1 " | THEIR=" $2
}'