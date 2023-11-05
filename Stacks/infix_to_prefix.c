#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 50

char stack[size];
int top = -1;

void push(char str)
{
    stack[ ++ top] = str;
}

char pop()
{
    if( top == -1)
    {
        printf("Invalid Infix expression\n");
    }
    return stack[ top--];
}

int check(char ch)
{
    switch(ch)
    {
        case '(' : return 0 ;
        case ')' : return 0 ;
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' : return 2;  
        case '^' : return 3;
    }
}

main()
{
    char infix[size],prefix[size],delete,temp;
    int i,j=0;
    printf("Enter a valid infix expression:\n");
    scanf("%s",infix);
    printf("Given infix expression: %s\n",infix);
    // Now i is pointing to the null char 
    for(i = strlen(infix)-1 ; i>=0 ; i--)
    {
        if( isalpha(infix[i]) || isdigit(infix[i]))
        {
            prefix[j++] = infix[i];
        }
        else if( infix[i] == ')')
        {
            push(infix[i]);
        }
        else if( infix[i] == '(')
        {
            while((delete=pop()) != ')')
            {
                prefix[j++] = delete ;
            }
        }
        else
        {
            while ( check( infix[i] ) < check( stack[top] )  && top != -1)
            {
                prefix[j++] = pop();
            }
                push(infix[i]);
        }
    }
        while( top != -1)
        {
            prefix[j++] = pop();
        }
        prefix[j] = '\0';
        // Now we need to reverse the whole prefix string
        for( i=0 ; i < j/2 ; i++)
        {
            temp = prefix[i];
            prefix[i] = prefix[ j-i-1];
            prefix[ j-i-1] = temp;
        }
        printf("Final prefix expression is %s\n",prefix);
}