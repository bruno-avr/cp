#!/bin/bash
clear
if [[ "$1" == *.cpp ]]; then
    g++ -std=c++17 -O2 $2 $1
else
    g++ -std=c++17 -O2 $2 $1.cpp
fi

for file in in
do
    ./a.out <$file
done