// Implementation of stacks to check whether an input string is a palindrome or not
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 50

int check_palindrome(char str[size])
{
    char stack[size];
    int i=0,j=0,top = -1;
    for( i=0 ; str[i] != '\0' ; i++)
    {
        if(str[i] == 'A' || str[i] == 'B' || str[i] == 'a' || str[i] == 'b')
        stack[ ++ top] = str[i];
        else if(str[i] == 'C' || str[i] == 'c')
        break;
    }
    if(i == strlen(str))
    return 0;
    // As i is pointing to char other than a and b hence i=i+1
    i++;
    for(j=i ; j<strlen(str) ; j++)
    {
        if(str[j] != stack[ top--])
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
    printf("Enter a xCy string that contains only a/A/b/B/c/C:\n");
    scanf("%s",str);
    f=check_palindrome(str);
    if(f == 1)
    {
        printf("%s is a palindrome of type xCy\n");
    }
    else
    printf("%s is not a palindrome of type xCy\n");
}