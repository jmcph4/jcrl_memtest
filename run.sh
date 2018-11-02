#!/bin/bash

rm bin/*.out bin/*.err # clean up any stale results

for filename in bin/*; do
    for ((i=0; i<=3; i++)); do
        valgrind --leak-check=full ./$filename $i > $filename"_"$i".out" 2> $filename"_"$i".err"
    done
done

pass=1

for filename in bin/*.err; do
    grep "no leaks are possible" $filename > /dev/null
    
    if [ $? -eq 1 ]
    then
        pass=0
        echo $filename" FAILED"
    fi
done

# return result accordingly
if [ $pass -eq 0 ]
then
    exit 1
else
    exit 0
fi

