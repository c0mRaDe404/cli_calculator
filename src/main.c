/**
 *  @file   main.c
 *  @author cOmRaDe404
 *  @brief  Main file 
 * 
 *  It's Just Driver Code,That's It Mate!
 * 
 */


#include "calc.h"
#include "Stack.h"
#include <ctype.h>
#define EXIT_SUCCESS 0


int main(void)
{

    char exp[100];
    int value,Running = 1;
        
    puts("\t\t\t\tterminal calculator (ver 1.0.0)\n");

    do {
    
    printf("\n>> ");
    scanf("%s",exp);

    value = evaluate(exp);
    printf("\n>> %d\n",value);
        

    }while(Running);


}