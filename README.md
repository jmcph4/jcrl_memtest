# jcrl_memtest #
---

This repository contains memory tests for [JCRL](https://github.com/jmcph4/jcrl).

These tests perform some simple operations on various data structures implemented by JCRL, then run the resulting executables under Valgrind and look for complaints from Memcheck.

## Usage ##
Full workflow is as follows:

    git clone https://github.com/jmcph4/jcrl.git # grab JCRL
    cd jcrl
    make # build JCRL
    cd ..
    git clone https://github.com/jmcph4/jcrl_memtest.git # grab jcrl_memtest
    cp jcrl/src/* jcrl_memtest/include # copy headers
    cp jcrl/build/* jcrl_memtest/lib # copy archive
    cd jcrl_memtest
    make all # build jcrl_memtest
    ./run.sh # run tests

