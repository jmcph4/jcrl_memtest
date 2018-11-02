#!/bin/bash
git clone https://github.com/jmcph4/jcrl.git
cd jcrl
make debug
cd ..
cp jcrl/src/* include/
cp jcrl/build/libjcrl.a lib/
rm jcrl -rf

