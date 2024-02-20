#include <stdio.h>
#ifndef CALC_H
#define CALC_H



typedef enum 
{

	
    // Addition
    PLUS=3,

    //Subtraction
    MINUS=3,

    //Multplication
    MULTIPLY=4,

    //Division
    DIVIDE=4,
    MODULO = 4,

    //Exponent
    EXP=5,

    //Parantheses and brackets
    L_BRACKET = 2,
    R_BRACKET = 1

}Token;



int isDigit(char);

int checkOperator(char);

int isSymbol(char);

double evaluate(char*);

int Calculator(char);

#endif
