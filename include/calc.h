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

    //Exponent
    EXP=4,


    //Parantheses
    L_PAREN=1,
    R_PAREN=1,
    L_CURLY =1,
    R_CURLY =1,
    L_SQUARE =1,
    R_SQUARE =1


}Token;



int isDigit(char);
int checkOperator(char);
int isSymbol(char);
int evaluate(char*);
int Calculator(char);

#endif
