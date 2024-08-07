#!/bin/bash

i=500;
j=0;

while [ $i -gt 0 ]; do
    ARG=$(./gen_nums)
    j=$(./push_swap "$ARG" | wc -l)
    res=$(./push_swap "$ARG" | ./checker_MAC $ARG)
    sleep 1
    echo "$j $res"
    if [ $j -gt 700 ]; then
        echo "TO BIG"
    fi
    ((i--))
done

