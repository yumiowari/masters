#!/bin/bash

gcc -c tree.c -o tree.o && gcc main.c tree.o -o main