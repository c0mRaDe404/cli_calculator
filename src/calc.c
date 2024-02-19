/**
 *
 *  @file   main.c
 *  @author cOmRaDe404
 *  @brief  Here's where the lexing and parsing happens.
 *
 */

#include <calc.h>
#include <stack.h>

Token Current_operator, Stack_operator; /*enum for tokens*/

Stack operand;  /* Stack for operand */
Stack operator; /* Stack for operator */

double evaluate(char *expression)
{

    int i = 0;
    operand.top = operator.top = - 1;

    while (expression[i] != '\0')
    {

        double Operand = 0;

        while (isDigit(expression[i]))
        {
            Operand = Operand * 10 + (expression[i] - '0');
            i++;
        }
        push(&operand, Operand);

        

        if (isSymbol(expression[i]))
            {
                    Current_operator  = checkOperator(expression[i]); /* operator we're handling right now*/
                    Stack_operator    = checkOperator(operator.data[operator.top]); /*operator which is now in the top of the operator stack*/

                    
                    if(!(isEmpty(&operator))&& Stack_operator >= Current_operator)
                    {
                        
                         char symbol = (char)pop(&operator); /*we've stored symbols as ASCII in the operator stack,So we're typecasting the corresponding ASCII to operator*/
                         Calculator(symbol); /*Passing the operator into Calculator function to calculate the value*/
                         Current_operator  = checkOperator(expression[i]);
                         Stack_operator    = checkOperator(operator.data[operator.top]);
                                  
                    }

                    else push(&operator,(int)expression[i]);
                

                    i++; // << Incrementing to the next character of the expression,YAYYYY!!!
            }   

            
    

    } // << Outer loop ends here :)


    //printf("the answer is %d at %d\n",operand.data[operand.top],operand.top);


  

    return operand.data[operand.top]; /*Return the output value which is stored in the top of the operand stack*/

}




/**
 *  
 * Simple calculator,that's it mate :)
 * 
 */



int Calculator(char symbol)
{

    double operand2 = pop(&operand);
    double operand1 = pop(&operand);

    switch (symbol)
    {

    case '+':
        push(&operand, operand1 + operand2);
        break;

    case '-':
        push(&operand, operand1 - operand2);
        break;

    case '*':
        push(&operand, operand1 * operand2);
        break;

    case '/':
        push(&operand, operand1 / operand2);
        break;

    case '%':
        push(&operand,operand1-((int)(operand1 / operand2)*operand2));
        break;

    case '^':
        push(&operand,(int)operand1^(int)operand2);
        break;

    default:
        push(&operand, operand1);
        break;
    }
}

int isDigit(char value)
{
    if (value >= '0' && value <= '9') return 1;

    else  return 0;
}

int isSymbol(char symbol)
{
    switch (symbol)
    {
    case '+': return 1;
    case '-': return 1;
    case '*': return 1;
    case '/': return 1;
    case '(': return 1;
    case ')': return 1;
    case ']': return 1;
    case '[': return 1;
    case '%': return 1;
    case '^': return 1;
    default : return 0;
    }
}

int checkOperator(char symbol)
{

    switch (symbol)
    {
    case '+': return PLUS;
    case '-': return MINUS;
    case '*': return MULTIPLY;
    case '/': return DIVIDE;
    case '%': return MODULO;
    case '^': return EXP;
    case '(': return L_BRACKET;
    case ')': return R_BRACKET;
    default : return 0;

    }
}
