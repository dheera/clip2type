#!/bin/bash

# Lasy to write a makefile right now

g++ -o clip2type clip2type.cpp -std=c++2b
sudo cp clip2type /usr/bin/
sudo chmod 4755 /usr/bin/clip2type
