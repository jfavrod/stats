#!/bin/bash

CC=gcc -ansi -Wall

all :
	make test_jlibcentral
	make central
	make clean

central : helpers.o central.o
	$(CC) -o central helpers.o central.o -lm

test_jlibcentral : helpers.o
	$(CC) -o test_jlibcentral helpers.o jlibcentral.test.c -lm

central.o : helpers.o jlibcentral.o
	$(CC) -c helpers.o jlibcentral.o central.c 

helpers.o : helpers.h
	$(CC) -c helpers.c

jlibcentral.o : jlibcentral.c
	$(CC) -c jlibcentral.c

clean :
	rm *.o

