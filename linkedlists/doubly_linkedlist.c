#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node *left , *right;
}*node;

node create_node( int input)
{
    node ptr = (node) malloc (sizeof(struct Node));
    ptr -> data = input;
    ptr -> left = ptr -> right = NULL;
    return ptr;
}

node insert_front( node head , node new)
{
    if( head == NULL)
    {
        head = new;
        return head;
    }
    new -> right = head;
    head -> left = new;
    head = new;
    return head;
}

node insert_end( node head , node new)
{
    if( head == NULL)
    {
        head = new;
        return head;
    }
    node temp = head;
    while( temp -> right != NULL)
    {
        temp = temp -> right;
    } 
    temp -> right = new;
    new -> left = temp;
    return head;
}

node delete_front( node head)
{
    if( head == NULL)
    {
        printf("List is empty\n");
        return head;
    }

    node temp = head;
    printf("%d is deleted from the list\n", temp -> data);
    head = head -> right;
    if(head != NULL)
        head -> left = NULL;
    free(temp);
    return head;
}

node delete_end( node head)
{
     if( head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    if( head -> right == NULL)
    {
        printf("%d is deleted\n",head -> data);
        return NULL;
    }
    node temp = head , prev = NULL ;
    while( temp -> right != NULL)
    {
        prev = temp;
        temp = temp -> right;
    }
    prev -> right = NULL;
    printf("%d is deleted\n",temp -> data);
    free( temp);
    return head;
}

void display( node head)
{
     if( head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while( head != NULL)
    {
        printf("%d -> ", head -> data);
        head = head -> right;
    }
    printf("\n");
}

main()
{
    node head = NULL , new;
    int choice , input ;
    for(;;)
    {
        printf("Enter an operation :\n");
        printf("1 to insert front / 2 to insert rear / 3 to delete front / 4 to delete rear / 5 to display\n");
        scanf("%d",&choice);
        if( choice == 1 || choice == 2)
        {
            printf("Enter an elmt that needs to be inserted:\n");
            scanf("%d",&input);
            // creating a new node
            new = create_node(input);
        }
        switch(choice)
        {
            case 1 : head = insert_front(head ,new);
                     break;
            case 2 : head = insert_end(head ,new);
                     break;
            case 3 : head = delete_front(head);
                     break;
            case 4 : head = delete_end(head);
                     break;
            case 5 : display(head);
                     break;
            default : printf("Invalid Choice\n");
                      exit(0);
        }
    }
}