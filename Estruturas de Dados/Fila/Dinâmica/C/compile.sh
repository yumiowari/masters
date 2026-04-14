#!/bin/bash

gcc -c queue.c -o queue.o && gcc main.c queue.o -o main
