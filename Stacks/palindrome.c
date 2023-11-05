// Implementation of stacks to check whether an input string is a palindrome or not
#include<stdio.h>
#include<stdlib.h>
#define size 50

int check_palindrome(char str[size])
{
    char stack[size];
    int i=0,top = -1;
    for( i=0 ; str[i] != '\0' ; i++)
    {
        stack[ ++ top] = str[i];
    }
    for( i=0 ; str[i] != '\0'; i++)
    {
        if(str[i] != stack[ top--])
        {
            return 0;
        }
    }
    return 1;
}

main()
{
    char str[size];
    int i,f=0;
    printf("Enter a string that needs to be checked:\n");
    scanf("%s",str);
    f=check_palindrome(str);
    if(f == 1)
    {
        printf("%s is a palindrome\n");
    }
    else
    printf("%s is not a palindrome\n");
}