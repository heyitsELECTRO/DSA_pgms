#include<stdio.h>
#include<stdlib.h>

 typedef struct Node
{
    int data;
    struct Node *link;
}*node;


node create_node(int input)
{
    node ptr = (node) malloc (sizeof(struct Node));
    ptr -> data = input;
    ptr -> link = NULL;
    return ptr;
}

node insert_front(node head , node new)
{
    if(head == NULL)
    {
        head = new;
        return head;
    }
    else
    {
        new -> link = head;
        head = new;
        return head;
    }
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

node delete_front(node head)
{
    if ( head == NULL)
    {
        printf("There is no elmt in the list\n");
        return head;
    }
    node temp = head;
    printf("%d is deleted\n", temp -> data);
    head = head -> link;
    free(temp);
    return head;
}

node delete_end(node head)
{
     if ( head == NULL)
    {
        printf("There is no elmt in the list\n");
        return head;
    }
    if( head -> link == NULL)
    {
        printf("%d is deleted\n", head -> data);
        free( head);
        return NULL;
    }
     node temp = head , prev = NULL;
     while( temp -> link != NULL)
     {
        prev = temp;
        temp = temp -> link;
     }  
      printf("%d is deleted\n", temp -> data); 
      prev -> link = NULL;
      free(temp);
      return head;
}

node display(node head)
{
    if(head == NULL)
    {
        printf("List is Empty\n");
        return head;
    }
    node temp = head;
    while(temp != NULL)
    {
        printf("%d -> ",temp -> data);
        temp = temp -> link;
    }
    printf("\n");
    return head;
}

node concatenate(node head1, node head2)
{
    if( head1 == NULL)
    {
        if(head2 == NULL)
        {
            printf("Both lists are empty\n");
            return head1;
        }
        head1 = head2;
        return head1;
    }
    node temp = head1;
    while( temp -> link != NULL)
    {
        temp = temp -> link;
    }
    temp -> link = head2;
    return head1;
}

main()
{
    node head1 = NULL , head2 = NULL , new;
    int choice, input;
    for(;;)
    {
        printf("Enter an operation :\n");
        printf("list 1 :- 1 to insert front / 2 to insert end / 3 to display\n");
        printf("list 2 :- 4 to insert front / 5 to insert end / 6 to display\n");
        printf("7 to concatenate & display\n");
        scanf("%d",&choice);
        if( choice == 1 || choice == 2 || choice == 4|| choice == 5)
        {
            printf("Enter an element that needs to be inserted:\n");
            scanf("%d",&input);
            new = create_node(input);
        }
        switch(choice)
        {
            case 1 : head1 = insert_front(head1 ,new);
                     break;
            case 2 : head1 = insert_end(head1 ,new);
                     break;
            case 3 : head1 = display(head1);
                     break;
            case 4 : head2 = insert_front(head2 ,new);
                     break;
            case 5 : head2 = insert_end(head2 ,new);
                     break;
            case 6 : head2 = display(head2);
                     break;
            // Use concatenate once after deleting elmt in list 2
            case 7 : head1 = concatenate(head1,head2);
                      printf("2nd list is concatenated in the first list\n");
                      break;
            default : printf("Invalid Choice\n");
                      exit(0);
        }
    }
}