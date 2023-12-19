#include <stdio.h>
#ifndef CALC_H
#define CALC_H



typedef enum 
{

    // Addition
    PLUS=1,

    //Subtraction
    MINUS=2,

    //Multplication
    MULTIPLY=3,

    //Division
    DIVIDE=4,

    //Exponent
    EXP=5,


    //Parantheses
    L_PAREN=6,
    R_PAREN=7

}Token;



int isDigit(char);
int checkOperator(char);
int isSymbol(char);
int evaluate(char[]);
int Calculator(char);

#endif