// C pgm to check whether given expression is having a valid parenthesis or not
#include<stdio.h>
#include<stdlib.h>
#define size 50

char stack[size];
int top = -1;

void push(char str)
{

    stack[ ++top] = str ;
}

char pop()
{
    if( top == -1)
    {
        printf("Right parenthesis is more than left parenthesis.Hence invalid\n");
        exit(0);
    }
    return stack[ top--];
}

int check_parenthesis(char left,char right)
{
    if( left == '(' && right == ')')
    return 1;
    else if( left == '[' && right == ']')
    return 1;
    else if( left == '{' && right == '}')
    return 1;
    else
    return 0;
}

main()
{
    char str[size],delete;
    int i,f=0;
    printf("Enter an expression whose parenthesis needs to be checked\n");
    scanf("%s",str);
    printf("%s\n",str);
    for(i=0 ; str[i] != '\0' ; i++)
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(str[i]);
        }
        else if(str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            delete = pop();
            // Now left(open) parenthesis is stored in delete and right(close) parenthesis is in str[i]
            if(check_parenthesis(delete,str[i]) == 0 )
            {
                printf("Invalid parenthesis\n");
                exit(0);
            }
        }
    }
    if( top == -1)
    {
        printf("Valid parenthesis\n");
    }
    // if top != -1 indicates that there are open parenthesis left out
    else
    {
        printf("Open parenthesis is more hence Invalid parenthesis\n");
    }
}