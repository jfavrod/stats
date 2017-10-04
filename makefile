#!/bin/bash

CC=gcc -ansi -Wall

all :
	make test_jlibcentral
	make test_jlibvariance
	make central
	make clean

central : helpers.o central.o
	$(CC) -o central helpers.o central.o -lm

test_jlibcentral : helpers.o
	$(CC) -o test_jlibcentral helpers.o jlibcentral.test.c -lm

test_jlibvariance : jlibcentral.o helpers.o
	$(CC) -o test_jlibvariance helpers.o jlibcentral.o jlibvariance.test.c -lm

central.o : helpers.o jlibcentral.o
	$(CC) -c helpers.o jlibcentral.o central.c 

helpers.o : helpers.h
	$(CC) -c helpers.c

jlibcentral.o : jlibcentral.h jlibcentral.c
	$(CC) -c jlibcentral.c

jlibvariance.o : jlibvariance.h jlibvariance.c
	$(CC) -c jlibvariance.c

clean :
	rm *.o

