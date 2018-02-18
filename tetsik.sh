#!/bin/bash

mkdir $1

for fType in $@
do
find ~ -iname "*.$fType" -exec cp {} ./$1/ \;
done

tar -cf "$2" $1 

echo "done"
