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


int main(void)
{

    char exp[100];
    puts("\t\t\t\tterminal calculator (ver 1.0.0)\n");
    printf(">> ");
    scanf("%s",exp);
    evaluate(exp);

}