#!/bin/sh
set -e
gcc -g eval.c ctrouve/*.c tests/01_libc/*.c tests/02_additional/*.c tests/tools.c -Itests/includes -Ictrouve/ 
