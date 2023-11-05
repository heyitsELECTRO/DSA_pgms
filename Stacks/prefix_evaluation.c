#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define size 50

int stack[size],top = -1;

void push( int num)
{
    stack[ ++top] = num;
}

int pop()
{
    if( top == -1)
    {
        printf("Invalid prefix expression\n");
        exit(0);
    }
    return stack[ top--];
}

int evaluate(int d1,int d2,char ch)
{
    switch(ch)
    {
        case '+' : return (d1+d2);
        case '-' : return (d1-d2);
        case '*' : return (d1*d2);
        case '/' : return (d1/d2);
        case '^' : return pow(d1,d2);
        default : return 0;
    }
}

main()
{
    char prefix[size];
    int i,d1,d2,num;
    printf("Enter a valid prefix expression:\n");
    scanf("%s",prefix);
    for( i= (strlen(prefix)) - 1 ; i>=0 ; i--)
    {
        if( isdigit(prefix[i]))
        {
            num = prefix[i] - 48 ;
            push(num);
        }
        else 
        {
            d1 = pop();
            d2 = pop();
            num = evaluate (d1,d2,prefix[i]);
            push(num);
        }
    }
    if(top != 0)
    {
        printf("Invalid expression\n");
    }
    num = pop();
    printf("The value of prefix expression %s is : %d\n",prefix,num);
}