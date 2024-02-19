/**
 *  @file   main.c
 *  @author cOmRaDe404
 *  @brief  Main file
 *
 *  It's Just Driver Code,That's It Mate!
 *
 */

#include <calc.h>
#include <stack.h>


int main(void)
{

    char exp[100];
    double value;

    puts("\t\t\t\tterminal calculator (ver 1.0.0)\n");

    while(1) {
        printf("\n>> ");
        scanf("%s", exp);

        if (*exp == 'q') return 0;
        value = evaluate(exp);
        printf("\n>> %.5lf\n", value);
    }


}
