#!/bin/bash

CC=gcc -ansi -Wall

all :
	make test_jlibcentral
	make test_jlibvariance
	make central
	make variance

central : helpers.o central.o
	$(CC) -o bin/central build/helpers.o build/central.o -lm

variance : helpers.o central.o variance.o
	$(CC) -o bin/variance build/helpers.o build/jlibcentral.o build/variance.o -lm

test_jlibcentral : helpers.o
	$(CC) -o bin/tests/test_jlibcentral build/helpers.o src/jlibcentral.test.c -lm

test_jlibvariance : jlibcentral.o helpers.o
	$(CC) -o bin/tests/test_jlibvariance build/helpers.o build/jlibcentral.o src/jlibvariance.test.c -lm

central.o : helpers.o jlibcentral.o
	$(CC) -c build/helpers.o build/jlibcentral.o src/central.c 
	mv central.o build/

variance.o : helpers.o jlibvariance.o
	$(CC) -c build/helpers.o build/jlibvariance.o src/variance.c 
	mv variance.o build/

helpers.o : src/inc/helpers.h
	$(CC) -c src/helpers.c
	mv helpers.o build/

jlibcentral.o : src/inc/jlibcentral.h src/jlibcentral.c
	$(CC) -c src/jlibcentral.c
	mv jlibcentral.o build/

jlibvariance.o : src/inc/jlibvariance.h src/jlibvariance.c
	$(CC) -c src/jlibvariance.c
	mv jlibvariance.o build/

clean :
	rm bin/central
	rm bin/variance
	rm bin/tests/test_jlib*
	rm build/*.o
