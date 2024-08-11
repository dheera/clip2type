#!/bin/bash

# Lasy to write a makefile right now

if [[ $1 == "" ]] then
    g++ -o clip2type clip2type.cpp -std=c++2b
elif [[ $1 == "install" ]] then
    sudo cp clip2type /usr/bin/
    sudo chmod 4755 /usr/bin/clip2type
else
    echo "no target blah blah"
fi
