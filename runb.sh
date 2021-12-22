#!/bin/sh
set -e
gcc -g -Wall -Wextra -Werror igaplich/*.c tests/tools.c tests/01_libc/*.c tests/02_additional/*.c tests/03_bonus/*.c eval.c -Iigaplich/ -Itests/includes -D BONUS 
