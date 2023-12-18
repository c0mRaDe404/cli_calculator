#include "calc.h"




int evaluate(char expression[])
{

    for(int i = 0;expression[i] != '\0';i++)
    {
        int operand = 0;

        if(isDigit(expression[i]))
        {
            printf("%c",expression[i]);
        }
    }

}




int isDigit(char value)
{
    if(value >= '0' && value <= '9')
        return 1;
    else return 0;
}
