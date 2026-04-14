#!/bin/bash

g++ -c queue.cpp -o queue.o && g++ main.cpp queue.o -o main
