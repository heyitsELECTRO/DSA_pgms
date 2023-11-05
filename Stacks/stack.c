// Implementation of different operations on stack using structures
#include<stdio.h>
#include<stdlib.h>
#define size 5

struct stack{
    int str[size],top;
};

// Here we use push function to insert an elmt in the stack
void push(struct stack *s,int input)
{
    if( s -> top == size - 1)
    {
        printf("Stack Overflow / Full \n");
        return;
    }
    (s -> top)++;
    s -> str[s -> top]=input;
}

int pop(struct stack *s)
{
    if( s -> top == -1)
    {
    return 0;
    }
    else
    {
    return (s -> str[s -> top--]);  // Post decrement of top value after returning to main()
    }
}

void display(struct stack s)
{
    int i;
    if( s.top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    for(i=s.top ; i>=0 ; i--)
    {
        printf("%d\n",s.str[i]);
    }
}

main()
{
   struct stack s;
   s.top = -1;
   int i,input,choice,delete;
   printf("Enter an operation that needs to be performed:\n");
   for(;;)
   {
    printf("Enter 1 to insert a no./ 2 to delete a no. / 3 to display the elmts of stack\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 : printf("Enter a number that needs to be inserted:\n");
                 scanf("%d",&input);
                 push(&s,input);
                 break;

        case 2 : delete=pop(&s);
                 if(delete == 0)
                 {
                 printf("Stack is Empty / Underflow\n");    
                 }
                 else
                 {
                    printf("Deleted element is %d and now top value is %d\n",delete,s.top);
                 }       
                 break;
        case 3 : printf("Elements of stack from top to the 0th index:\n");
                 display(s);
                 break;
        default : printf("Invalid choice\n");
                  exit(0);
    }
   }
}