#include <stdio.h> //stdio header included,cuz i'm a lazy person to type that again lol

#ifndef STACK_H
#define STACK_H

#define SIZE 100

typedef struct
{
    int top;
    int data[SIZE];

} Stack;

void push(Stack *, int);

int pop(Stack *);

int isFull(Stack *);

int isEmpty(Stack *);

#endif