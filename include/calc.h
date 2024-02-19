#include <stdio.h>
#ifndef CALC_H
#define CALC_H



typedef enum 
{

	
    // Addition
    PLUS=2,

    //Subtraction
    MINUS=2,

    //Multplication
    MULTIPLY=3,

    //Division
    DIVIDE=3,

    MODULO = 3,

    //Exponent
    EXP=4,


    //Parantheses and brackets
    L_BRACKET = 1,
<<<<<<< HEAD
    R_BRACKET = 1
=======
    R_BRACKET = -1
>>>>>>> update


}Token;



int isDigit(char);

int checkOperator(char);

int isSymbol(char);

double evaluate(char*);

int Calculator(char);

#endif
