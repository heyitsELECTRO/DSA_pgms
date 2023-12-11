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

node concatenate(node head1 , node head2)
{
    if( head1 == NULL)
    {
        if( head2 == NULL)
        {
            printf("Both lists are empty\n");
            return NULL;
        }
        head1 = head2;
        return head1;
    }
    node temp = head1;
    while(temp -> right != NULL)
    {
        temp = temp -> right;
    }
    temp -> right = head2;
    head2 -> left = temp;
    return head1;
}

main()
{
    node head1 = NULL ,head2 = NULL, new;
    int choice , input ;
    for(;;)
    {
        printf("Enter an operation :\n");
        printf("List 1 :- 1 to insert front / 2 to insert end / 3 to display\n");
        printf("List 2 :- 4 to insert front / 5 to insert end / 6 to display\n");
        printf("7 to concatenate\n");
        scanf("%d",&choice);
        if( choice == 1 || choice == 2 || choice == 4 || choice == 5)
        {
            printf("Enter an elmt that needs to be inserted:\n");
            scanf("%d",&input);
            new = create_node(input);
        }
        switch(choice)
        {
            case 1 : head1 = insert_front(head1 ,new);
                     break;
            case 2 : head1 = insert_end(head1 ,new);
                     break;
            case 3 : display(head1);
                     break;
            case 4 : head2 = insert_front(head2 ,new);
                     break;
            case 5 : head2 = insert_end(head2 ,new);
                     break;
            case 6 : display(head2);
                     break;
            case 7 : head1 = concatenate(head1,head2);
                     break;
            default : printf("Invalid Choice\n");
                      exit(0);
        }
    }
}