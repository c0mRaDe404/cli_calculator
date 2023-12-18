#include <stdio.h>
#ifndef CALC_H
#define CALC_H
#define SIZE 100

typedef struct
{
    int top;
    int data[SIZE];
}stack;

int isDigit(char);

int evaluate(char[]);

#endif