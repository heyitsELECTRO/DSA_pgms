#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define size 50

int stack[size] , top = -1;

void push( int num)
{
    stack[ ++top] = num;
}

int pop()
{
    return stack[ top--];
}

int evaluate(int d1, int d2, char operator)
{
    switch(operator)
    {
        case '+' : return (d2+d1);
        case '-' : return (d2-d1);
        case '*' : return (d2*d1);
        case '/' : return (d2/d1);
        case '^' : return (pow(d2,d1));
        default : return 0;
    }
}

main()
{
    char postfix[size];
    int i,d1,d2,num;
    // d1 and d2 indicates 1st and 2nd deleted elmts respectively
    printf("Enter a valid postfix expression:\n");
    scanf("%s",postfix);
    for(i=0 ; postfix[i] != '\0' ; i++)
    {
        if( isdigit(postfix[i]) )
        {
            num = postfix[i] - '0';
            push(num);
        }
        else 
        {
            d1 = pop();
            d2 = pop();
            num = evaluate(d1,d2,postfix[i]);
            push(num);
        }
    }
    if(top == 0) // Indicates that only one elmt left out after evaluation
    num = pop();
    printf("Evaluation of postfix expression %s is : %d\n",postfix,num);
}