#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* createnode(int num)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = num;
    ptr -> link = NULL;
    return ptr;
}

void display(struct node *head)
{
    struct node *temp = head;
    if(temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(temp != NULL)
    {
        printf("%d -> ",temp -> data);
        temp = temp -> link;
    }
    printf("\n");
}

main()
{
  struct node *head , *temp , *new;
  struct node *prev , *next;
  head = NULL;
  int ch,num,key;
  static int f;
  for(;;)  
  {
    printf("1 for if/ 2 to ie/ 3 to df/ 4 to de/ 5 to display\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : printf("Enter elmt that needs to be inserted:\n");
                 scanf("%d",&num);
                 new = createnode(num);
                 if(head == NULL)
                 {
                    head = temp = new;
                 }
                 else
                 {
                   new -> link = head ;
                   head = new;
                 }
                 break;
        case 2 : printf("Enter elmt that needs to be inserted:\n");
                 scanf("%d",&num);
                 new = createnode(num);
                 if(head == NULL)
                 {
                    head = temp = new;
                 }
                 else{
                    temp = head;
                    while(temp -> link != NULL)
                    {
                        temp = temp -> link;
                    }
                    temp -> link = new;
                    temp = new;
                 }
                 break;
        case 3 : if(head == NULL)
                 {
                    printf("List is empty\n");
                 }
                 else
                 {
                    printf("%d is deleted from the list\n",head -> data);
                    head = head -> link;
                 }
                 break;
        case 4 :  if(head == NULL)
                 {
                    printf("List is empty\n");
                 }
                 else
                 {
                    temp = head;
                    while(temp -> link != NULL)
                    {
                        prev = temp ;
                        temp = temp -> link;
                    }
                    printf("%d is deleted from the list\n",temp -> data);
                    prev -> link = NULL;
                 }
                 break;
        case 5 : printf("Enter elmt that needs to be inserted and also before which elmt:\n");
                 scanf("%d %d",&num,&key);
                 new = createnode(num);
                 prev = next = NULL;
                 temp = head;
                 while(temp -> data != key && temp != NULL)
                 {
                    prev = temp;
                    next = temp = temp -> link;
                 }
                 if(temp -> data == key) 
                 {
                    if(prev == NULL || next == NULL)
                    {
                        new -> link = head;
                        head = new;
                    }
                    else
                    {
                    prev -> link = new;
                    new -> link = next;
                    }
                 }
                 else
                 printf("Key not found\n");
                 break;  
        case 6 : display(head);
                 break;
        default : printf("Invalid Choice\n");
                  exit(0);       
    }
  } 
}