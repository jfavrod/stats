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

#define FALSE 0
#define TRUE 1
#define MAX_CHARS 81

#endif

