/**
 * 
 *  @file   main.c
 *  @author cOmRaDe404
 *  @brief  Here's where the lexing and parsing happens.
 * 
 */



#include "calc.h"
#include "Stack.h"







Token Current_operator,Stack_operator; /*enum for tokens*/


Stack operand; /* Stack for operand */
Stack operator; /* Stack for operator */



int evaluate(char expression[])
{
    operand.top = operator.top = -1; // Setting up both operand & operator stack's top 


   

    for(int i = 0;expression[i] != '\0';)
    {
        int Operand = 0; //holds the number which converted from string\

        Current_operator = checkOperator(expression[i]); // gets the current operator precedence value
        Stack_operator = checkOperator(operator.data[operator.top]); //gets stack operator precedence

        
        while(isDigit(expression[i]))
        {
            Operand = Operand*10+(expression[i]-'0'); //converts the string to int (char by char conversion)
            i++;
        }
        push(&operand,Operand); //pushing the final value of Operand onto operand stack




        if (isSymbol(expression[i]))
            {
                if(isEmpty(&operator))
                {
                push(&operator,expression[i]);
                }


                 if(Current_operator < Stack_operator)
                {
                    printf("%d\n",Current_operator);
                    printf("%d",Stack_operator);
                    //push(&operand,Calculator(pop(&operand)));
                }




                i++; // << Increment dont touch it at all cost
            }   

    }




    // for(int i = 0;i<10;i++)
    // {
    //         printf("%d\n",operand.data[i]);
    // //                                                      <<    debugging purpose    
    //        // printf("%c\n",operator.data[i]);
    // }
    
       


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






int checkOperator(char symbol)
{
    switch (symbol)
    {
    case '+':
        return PLUS;
        

    case '-':
        return MINUS;
        

    case '*':
        return MULTIPLY;
    

    case '/':
        return DIVIDE;
        

    case '^':
        return EXP;

    case '(':
        return L_PAREN;

    case ')':
        return R_PAREN;    
    
    default:
        break;
    }

}

int Calculator(char symbol)
{

    int operand1 = pop(&operand);
    int operand2 = pop(&operand);

    switch (symbol)
    {

    case '+':
        return operand2+operand1;

    case '-':
        return operand2-operand1;
    
    case '*':
        return operand2*operand1;

    case '/':
        return operand2/operand1;

    default:
        break;
    }

}