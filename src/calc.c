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
        
        top:
            Current_operator = checkOperator(expression[i]);
            Stack_operator = checkOperator(operator.data[operator.top]);

            if (!(isEmpty(&operator))&&(Stack_operator >= Current_operator))
            {
                char symbol = (char)pop(&operator);
                Calculator(symbol);
                goto top;    
            }

            else push(&operator,(double) expression[i]);
            
            i++;
        }
    }

    while (!(isEmpty(&operator)))
    {
        char symbol = (char)pop(&operator);
        Calculator(symbol);
    }

    //printf("%c is operator and %d is top of the operator stack",(char)operator.data[operator.top+1],operator.top);

   
    pop(&operand);

}







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
