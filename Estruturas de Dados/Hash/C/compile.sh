#!/bin/bash

gcc -c hash.c -o hash.o && gcc main.c hash.o -o main
