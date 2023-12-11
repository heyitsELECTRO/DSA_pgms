#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data ;
    struct Node *link;
}*node;

node createnode(int item)
{
    node ptr = (node)malloc(sizeof(struct Node));
    ptr -> data = item;
    ptr -> link = NULL;
    return ptr;
}

node insert_front(node head, node new)
{
    if( head == NULL)
    {
        head = new ;
        return head;
    }
    new -> link = head ;
    head = new ;
    return head;
}

node insert_end(node head , node new)
{
    if( head == NULL)
    {
        head = new;
        return head;
    }
    if( head -> link == NULL)
    {
        head -> link = new ;
        return head;
    }
    node temp = head;
    while( temp -> link != NULL)
    {
        temp = temp -> link;
    }
    temp -> link = new;
    return head ;
}


node delete_front( node head)
{
    if( head == NULL)
    {
        printf("List is empty\n");
        return head; 
    }
    if ( head -> link == NULL)
    {
        printf("%d is deleted\n",head -> data);
        free( head);
        return NULL;
    }
    node cur = head ;
    printf("%d is deleted\n",head -> data);
    head = head -> link ;
    free(cur);
    return head;
}

node delete_end( node head)
{
    if( head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    if ( head -> link == NULL)
    {
        printf("%d is deleted\n",head -> data);
        free( head);
        return NULL;
    }
    node temp = head ;
    node prev = NULL ;
    while( temp -> link != NULL)
    {
        prev = temp;
        temp = temp -> link;
    }
    printf("%d is deleted\n",temp -> data);
    prev -> link = NULL;
    free (temp);
    return head ;
}



void display(node head)
{
    node temp = head ;
    while(temp != NULL)
    {
        printf("%d -> ", temp -> data);
        temp = temp -> link;
    }
    printf("NULL \n");
}

main()
{
    node head = NULL,new;
    int choice,item,ch;
    printf("Press 1 to implement stack /2 to queue:\n");
    scanf("%d",&choice);
    if(choice == 1)
    {
       printf("Stack Implementation\n");
       for(;;)
       {
         printf("Enter 1 to push an elmt / 2 to pop topmost elmt / 3 to display:\n");
         scanf("%d",&ch);
         switch(ch)
         {
            case 1 : printf("Enter an elmt that needs to be inserted:\n");
                     scanf("%d",&item);
                     new = createnode(item);
                     head = insert_front(head,new);
                     break;
            case 2 : head = delete_front(head);
                     break;
            case 3 : display(head);
                     break;
            default : printf("Invalid Choice\n");
                      exit(0);
         }
       }
    }
    else if( choice == 2)
    {
        printf("Queue Implementation\n");
       for(;;)
       {
         printf("Enter 1 to insert an elmt / 2 to delete an elmt / 3 to display:\n");
         scanf("%d",&ch);
         switch(ch)
         {
            case 1 : printf("Enter an elmt that needs to be inserted:\n");
                     scanf("%d",&item);
                     new = createnode(item);
                     head = insert_end(head,new);
                     break;
            case 2 : head = delete_front(head);
                     break;
            case 3 : display(head);
                     break;
            default : printf("Invalid Choice\n");
                      exit(0);
         }
       }
    }
    else
    {
        printf("Invalid choice of Data Structure\n");
        exit(0);
    }
}