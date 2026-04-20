#!/bin/bash

g++ -c list.cpp -o list.o && g++ main.cpp list.o -o main
