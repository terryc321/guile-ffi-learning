#!/bin/bash



# \ slash comes before newline 
gcc `pkg-config guile-3.0 --cflags` \
    -shared -o libguile-type.so -fPIC type.c 










