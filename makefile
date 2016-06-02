#!/bin/bash

CC=gcc -ansi -Wall

all :
	make central
	make clean

central : helpers.o central.o
	$(CC) -o central helpers.o central.o -lm

helpers.o : helpers.h
	$(CC) -c helpers.c

central.o : central.c
	$(CC) -c central.c

clean :
	rm *.o

