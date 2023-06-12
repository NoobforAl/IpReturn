#!/bin/bash

if [ -f /tmp/ipreturn ]; then
    rm /tmp/ipreturn
fi

gcc -o /tmp/ipreturn main.c -lulfius 

/tmp/ipreturn