#include "calc.h"

int main(void)
{

    char exp[100];
    puts("\t\t\t\tterminal calculator (ver 1.0.0)\n");
    printf(">> ");
    scanf("%s",exp);
    evaluate(exp);

}