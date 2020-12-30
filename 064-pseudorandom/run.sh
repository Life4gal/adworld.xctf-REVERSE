gcc -fpic -shared sleep.c -o sleep.so

LD_PRELOAD=./sleep.so ./pseudorandom

# gdb
# set exec-wrapper env 'LD_PRELOAD=./sleep.so'
# file pseudorandom
# run
