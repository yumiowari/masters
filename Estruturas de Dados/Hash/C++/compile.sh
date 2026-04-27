#!/bin/bash

g++ -c hash.cpp -o hash.o && g++ main.cpp hash.o -o main
