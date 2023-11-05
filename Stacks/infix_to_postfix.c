#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define size 50

char stack[size];
int top = -1;

void push(char str)
{
    stack[ ++top] = str;
}

char pop()
{
    if(top == -1)
    {
        printf("Invalid expression\n");
        exit(0);
    }
    return stack[ top--];
}

int check(char str)
{
    switch(str)
    {
        case '(' : return 0;
        case '+' : 
        case '-' : return 1;
        case '*' :
        case '/' : return 2;
        case '^' : return 3;
    }
}

main()
{
    int i,j=0;
    char infix[size],postfix[size],delete;
    printf("Enter a valid infix expression:\n");
    scanf("%s",infix);
    for(i=0 ; infix[i] != '\0' ; i++)
    {
        if( isdigit(infix[i]) || isalpha(infix[i]) )
        {
            postfix[j++] = infix[i];
        }
        else if( infix[i] == '(')
        {
            push(infix[i]);
        }
        else if( infix[i] == ')')
        {
            while((delete = pop()) != '(')
            {
                postfix[ j++] = delete;
            }
        }
        else
        {
            while ( check(infix[i]) <= check(stack[top]) && top != -1)
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while( top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("Final postfix expression is %s\n",postfix);
}