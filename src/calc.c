/**
 * 
 *  @file   main.c
 *  @author cOmRaDe404
 *  @brief  Here's where the lexing and parsing happens.
 * 
 */



#include "calc.h"
#include "Stack.h"




Stack operand;
Stack operator;



int evaluate(char expression[])
{
    operand.top = operator.top = -1;

    push(&operand,20);


    printf("data is %d and postion is %d",operand.data[0],operand.top);



    for(int i = 0;expression[i] != '\0';i++)
    {
        int operand = 0;

        if(isDigit(expression[i]))
        {
            operand = operand*10+(expression[i]-'0');
        }
        
    }

}




int isDigit(char value)
{
    if(value >= '0' && value <= '9')
        return 1;
    else return 0;
}
