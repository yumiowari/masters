#!/bin/bash

g++ -c stack.cpp -o stack.o && g++ main.cpp stack.o -o main
