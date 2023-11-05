#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 50

char stack[size][size];
int top = -1;

void push(char str[size])
{
    strcpy( stack[ ++top],str);
}

void pop(char str[size])
{
    strcpy(str , stack[ top--]);
}

main()
{
    int i;
    char prefix[size],infix[size],d1[size],d2[size],str[size];
    // d1 and d2 indicates 1st and 2nd deleted elmts respectively
    printf("Enter a valid prefix expression:\n");
    scanf("%s",prefix);
    printf("Given prefix expression is %s\n",prefix);
    for( i=(strlen(prefix)-1) ; i>=0 ; i--)
    {
        str[0]=prefix[i];
        str[1]='\0';
        if( isalpha(prefix[i]) || isdigit(prefix[i]) )
        {
            push(str);
        }
        else
        {
            pop(d1);
            pop(d2);
            strcpy(infix,"(");
            strcat(infix,d1);
            strcat(infix,str);
            strcat(infix,d2);
            strcat(infix,")");
            push(infix);
        }
    }
     if( top != 0)
     {
        printf("Invalid prefix expression\n");
        exit(0);
     }
    // Now we pop and copy the last elmt of the stack into the infix
    strcpy(infix, stack[ top--]);
    printf("Final infix expression is %s\n",infix);
}