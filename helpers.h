/**********************************************************************
//
// NAME:        helpers.h
//
// AUTHOR:      Jason Favrod
//
// DATE:        27 May 2016     
//
// DESCRIPTION: Header file for helpers.c.
//
***********************************************************************/
#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void clear_input_buff(void);
int get_int(void);
int inrange(int x, int low, int high);
int str_clear(char str[]);
int str_replace(char needle, char haystack[], char replace);
int round_up(int x, int round);
int validateCSV(char numbersCSV[]);
void translateCSV(char numbersCSV[], double numbers[], int * count);
int ascending(const void *p, const void *q);
int in_darray(double needle, double haystack[], int count);
void print_darray(double a[], int count);
int darray_indexof(double number, double a[], int count);
void print_iarray(int a[], int count);
int max_int(int a[], int count);

#define FALSE 0
#define TRUE 1
#define MAX_CHARS 81

#endif

