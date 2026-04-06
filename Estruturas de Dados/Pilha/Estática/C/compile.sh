#!/bin/bash

gcc -c stack.c -o stack.o && gcc main.c stack.o -o main
