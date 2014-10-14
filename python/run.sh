#!/bin/bash

gcc -I /usr/include/SDL -I/usr/include/python3.4m -o main -Wall main.c script.c -lSDL -lSDL_image -lpython3.4m && ./main

