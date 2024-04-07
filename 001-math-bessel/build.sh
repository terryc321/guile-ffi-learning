#!/bin/bash

# make a shared library from bessel.c file
# need guile-3.0 development headers notably libguile.h
# we do not need --libs switch with pkg-config since only making library , not making full binary

# \ slash comes before newline 
gcc `pkg-config guile-3.0 --cflags` \
    -shared -o libguile-bessel.so -fPIC bessel.c 









