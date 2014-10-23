#!/bin/bash

g++ -I /usr/include/SDL -I/usr/include/python3.4m -o main -Wall main.cpp script.cpp -lSDL -lSDL_image -lpython3.4m -lboost_python3 -lboost_system -lboost_thread && ./main

