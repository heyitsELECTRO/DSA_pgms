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
    node temp = head;
    while( temp -> link != NULL)
    {
        temp = temp -> link;
    }    
    temp -> link = new;
    return head;
}

node reverse(node head)
{
    node curr = head, prev = NULL, next;
    while(curr != NULL)
    {
        next = curr -> link;
        curr -> link = prev;
        prev = curr;
        curr = next;
    }
    return prev;
    // node next = NULL;
    // node temp = head -> link;
    // while( temp -> link != NULL)
    // {
    //     if( next == NULL)
    //     {
    //         head -> link = NULL;
    //     }
    //     next = temp -> link;
    //     temp -> link = head;
    //     head = temp;
    //     temp = next;
    // }
    // temp -> link = head;
    // head = temp;
    // return head; 
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
    int ch,item;
    for(;;)
    {
        printf("\nEnter 1 to insert at front/ 2 to insert at end/ 3 to reverse the list/\n");
        printf("4 to display the list\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : printf("Enter the elmt that needs to be inserted:\n");
                     scanf("%d",&item);
                     new = createnode(item);
                     head = insert_front(head, new);
                     break;

            case 2 : printf("Enter the elmt that needs to be inserted:\n");
                     scanf("%d",&item);
                     new = createnode(item);
                     head = insert_end(head, new);
                     break;

            case 3 : head = reverse(head);
                     break;

            case 4 : display(head);
                     break;
                     
            default : printf("Invalid Choice\n");
                      exit(0);
} 
    }
}