/**
 *  @file   Stack.c
 *  @author cOmRaDe404
 *  @brief  Stack implementation 
 * 
 *  I Just Wrote My Own Stack Implemntation Because I'm Bored.
 *    
 * 
 */


#include "Stack.h"


void push(Stack* s,int data)
{
    if(!(isFull(s)))
    s->data[++s->top]= data;

    else 
    {
        fprintf(stderr,"StackOverFlowError:Stack is Full");
    }
}



int pop(Stack* s)
{
    if(!(isEmpty(s)))
    return s->data[s->top--];

    else
    {
    fprintf(stderr,"StackUnderFlow:Stack is Empty");
    }
}



int isFull(Stack* s)
{
    if(s->top == SIZE) return 1;
    else return 0;
}




int isEmpty(Stack* s)
{
    if(s->top == -1) return 1;
    else return 0;
}




// Stack num;

// int main()

// {
   

//     num.top = -1;
//     push(&num,10);
//     push(&num,20);

//     printf("%d",num.data[1]); 

// }
