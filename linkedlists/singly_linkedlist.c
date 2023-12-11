/* Performing different operations on a singly linked list such as :- 
 insert at front , insert at rear, insert before an elmt , insert after an elmt ,
 insert at a position , delete from front , delete from rear , delete at a position ,
 display
*/


#include<stdio.h>
#include<stdlib.h>


struct Node {
    int data ;
    struct Node *link;
};

typedef struct Node *node;

int number_of_nodes(node head)
{
    node temp = head;
    int count = 0;
    while(temp != NULL)
    {
        temp = temp -> link;
        count ++;
    }
    return count;
}

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

node insert_before_elmt( node head , node new)
{
    if( head == NULL)
    {
        printf("There is no node in the list\n");
        return NULL;
    }
    int key;
    printf("Enter before which elmt you need to insert new node :\n");
    scanf("%d",&key);
    if(head -> data == key)
    {
        head = insert_front(head , new); 
        return head;
    }
    node temp = head , prev;
    while( temp -> data != key && temp -> link != NULL)
    {
        prev = temp;
        temp = temp -> link;
    }
    if( temp -> data == key)
    {
        new -> link = temp;
        prev -> link = new;
        return head;
    }
    else
    {
        printf("%d not found in the list \n", key);
        return head;
    }
}

node insert_after_elmt( node head , node new)
{
    int key;
    printf("Enter after which elmt you need to insert new node :\n");
    scanf("%d",&key);
    if ( head -> data == key)
    {
        new -> link = head -> link;
        head -> link = new;
        return head;
    }
    node temp = head , next;
    while(temp -> data != key && temp -> link != NULL)
    {
        temp = temp -> link;
        next = temp -> link;
    }
    if(temp -> link == NULL)
    {
        head = insert_end( head , new);
    }
    else if( temp -> data == key)
    {
        new -> link = next;
        temp -> link = new;
    }
    else
    {
        printf("%d not found in the list\n",key);
    }
    return head;
}

node insert_at_position( node head , node new)
{
    node temp = head , prev;
    int position , count = 0 , i=1;
    count = number_of_nodes(head);
    printf("No.of nodes in the list = %d\n",count);
    printf("Enter at which position u need to insert inside the list\n");
    scanf("%d",&position);
    if( position < 1 || position > count )
    {
        printf("There are %d elmts in the list\n",count);
        return head;
    }

    while( i != position )
    {
        prev = temp;
        temp = temp -> link;
        i++;
    }
    if(position == 1)
    {
        head = insert_front(head , new);
        return head;
    }
    new -> link = temp;
    prev -> link = new;
    return head;
}

node delete_front( node head)
{
    if( head == NULL)
    {
        printf("List is empty\n");
        return head; // return NULL
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

node delete_at_position( node head)
{
    node temp = head , prev , next;
    int position , count , i =1;
    count = number_of_nodes(head);
    printf("No.of nodes in the list = %d\n",count);
    printf("Enter at which position u need to insert inside the list\n");
    scanf("%d",&position);
    if( position < 1 || position > count )
    {
        printf("There are %d elmts in the list\n",count);
        return head;
    }
    else if( position == 1)
    {
        head = delete_front(head);
    }
    else if( position == count)
    {
        head = delete_end(head);
    }
    else
    {
        while( i != position)
        {
            prev = temp ;
            temp = temp -> link;
            next = temp -> link;
            i++;
        }
        prev -> link = next ;
        printf("%d is deleted\n",temp -> data);
        free(temp);
    }
    return head;
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
        printf("\nEnter 1 to insert at front/ 2 to insert at end/ 3 to insert before an elmt /\n");
        printf("4 to insert after an elmt / 5 to insert at a postiton / 6 to delete at front /\n");
        printf("7 to delete at end / 8 to delete at a position / 9 to display:\n");
        scanf("%d",&ch);
        if(ch == 1 || ch == 2 || ch == 3 || ch == 4 || ch == 5 )
        {
            printf("Enter the elmt that needs to be inserted:\n");
            scanf("%d",&item);
            new = createnode(item);
        }
        switch(ch)
        {
            case 1 : head = insert_front(head, new);
                     break;

            case 2 : head = insert_end(head, new);
                     break;

            case 3 : head = insert_before_elmt( head , new);
                     break;

            case 4 : head = insert_after_elmt( head , new);
                     break;
            
            case 5 : head = insert_at_position( head , new);
                     break;

            case 6 : head = delete_front(head);
                     break;

            case 7 : head = delete_end(head);
                     break;

            case 8 : head = delete_at_position(head);
                     break;

            case 9 : display(head);
                     break;

            default : printf("Invalid Choice\n");
                      exit(0);
        }
    }
}