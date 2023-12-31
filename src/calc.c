/**
 * 
 *  @file   main.c
 *  @author cOmRaDe404
 *  @brief  Here's where the lexing and parsing happens.
 * 
 */



#include <calc.h>
#include <stack.h>





Token Current_operator,Stack_operator; /*enum for tokens*/


Stack operand; /* Stack for operand */
Stack operator; /* Stack for operator */



/**
 * 
 *  
 * Function that evaluates the given expression by spliting the expression into tokens
 * 
 * 
 */

int evaluate(char* expression)
{

    int i = 0;
    operand.top = operator.top = -1; // Setting up both operand & operator stack's top 
    


    while (expression[i] != '\0')
    {
 
         int Operand = 0;//holds the number which converted from string

              
        while(isDigit(expression[i]))
        {
            Operand = Operand*10+(expression[i]-'0'); //converts the string to int (char by char conversion)
            i++;
        }
        push(&operand,Operand); //pushing the final value of Operand onto operand stack
       

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
    
    int operand2 = pop(&operand); /*This is kinda ridic right? , You have to know that since we're using stack we're popping out the topmost element,DON'T FORGET THE LIFO ORDER*/
    int operand1 = pop(&operand);/*Since we're popping out the lastest element from the stack we've to handle the order of the operands ourselves*/

    //printf("operand 1 = %d operand 2 = %d and the top is %d and the top element is %d\n",operand1,operand2,operand.top,operand.data[operand.top]);
    
    switch (symbol)
    {

    case '+':
        push(&operand,operand1+operand2);
        break;

    case '-':
        push(&operand,operand1-operand2);
        break;
    
    case '*':
        push(&operand,operand1*operand2);
        break;

    case '/':
        push(&operand,operand1/operand2);
        break;

    default:
        push(&operand,operand1);
        break;
    }

}




/**
 * Function to find whether the character is digit or something else
 * 
 */



int isDigit(char value)
{
    if(value >= '0' && value <= '9') return 1;
    else return 0;
}



/**
 * 
 * Function to find the symbol among the expression
 *  
 */


int isSymbol(char symbol)
{

    if(symbol >='('|| symbol <= '/') return 1;
    else return 0;

}



/**
 *  
 * Checking the operator precedence using enum constants
 * 
 */


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
        return L_BRACKET;

    case ')':
        return R_BRACKET;    
    
    default:
        return 0;
    }

}


