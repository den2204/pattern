#!/bin/bash
for i in `ls ??`
do
	echo "====>$i<===="
	echo "Input file:"
	head -n 10 $i
	echo "Output file:"
	./$1 < $i
	echo ""
done 
