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

   

    for(int i = 0;expression[i] != '\0';)
    {
        int Operand = 0;

        
        while(isDigit(expression[i]))
        {
            Operand = Operand*10+(expression[i]-'0');
            i++;
        }

        push(&operand,Operand);
        

         if (isSymbol(expression[i]))
        {
            push(&operator,expression[i]);
            i++;
        }
   
        
    } // << Loop ends here


    printf("%d\n",operand.data[0]);
      printf("%d\n",operand.data[1]);
        printf("%c\n",operator.data[0]);
          printf("%c\n",operator.data[1]);

}





int isDigit(char value)
{
    if(value >= '0' && value <= '9')
        return 1;
    else return 0;
}


int isSymbol(char symbol)
{
    if(symbol >='('|| symbol <= '/' ) return 1;
    else return 0;

}

int checkPriority(char symbol)
{
    if(symbol == '+' || symbol == '-') return 0;
    if(symbol == '*' || symbol == '/') return 1;
    if(symbol == '(' || symbol == ')') return 2;
}