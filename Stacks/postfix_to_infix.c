// Postfix to Infix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 50

char st[size][size];
int top=-1;

void push(char ch[size])
{
  top++;
  strcpy(st[top],ch);
}

void pop(char ch[size])
{
 if(top == -1)
 {
     printf("Invalid postfix expression\n");
     exit(0);
 }
 strcpy(ch,st[top--]);
}


main()
{
 char in[size],pf[size],d1[size],d2[size],ch[2];
 // in -> infix , pf -> postfix , d1 and d2 represent popped elmts
 int i=0;
 printf("Enter a valid postfix expression:\n");
 scanf("%s",pf);
 printf("Given Postfix expression is %s\n",pf);
  for(i=0;pf[i]!='\0';i++)
 {
    //copying character (pf[i]) into a string (ch)
      ch[0]=pf[i];
      ch[1]='\0';
    if(isdigit(pf[i]) || isalpha(pf[i]))
    {
        push(ch);
    }
    else
    {
        pop(d1);
        pop(d2);
        strcpy(in,"(");
        strcat(in,d2);  
        strcat(in,ch);
        strcat(in,d1);
        strcat(in,")");
        //instead of using above 5 statements (multiple strcpy() and strcat()) we can use single below statement 
       // sprintf(in,"(%s%s%s)",d2,ch,d1);
        push(in);
    } 
 }
  if(top != 0)
  {
    printf("Invalid postfix Expression\n");
    exit(0);
  }
  strcpy(in,st[top--]);
  printf("Final Infix expression is %s and top value is %d\n",in,top);
}