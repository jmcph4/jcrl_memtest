#!/bin/bash

rm bin/*.out bin/*.err # clean up any stale results

for filename in bin/*; do
    for ((i=0; i<=3; i++)); do
        valgrind --leak-check=full ./$filename $i > $filename"_"$i".out" 2> $filename"_"$i".err"
    done
done

for filename in bin/*.err; do
    grep "no leaks are possible" $filename > /dev/null
    
    if [ $? -eq 1 ]
    then
        echo $filename" FAILED"
    fi
done

