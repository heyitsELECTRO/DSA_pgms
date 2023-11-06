#include<stdio.h>
#include<stdlib.h>
#define size 5

int lqueue[size], front = 0,rear  = -1;

void enque(int input)
{
    if( rear  == size -1)
    {
        printf("Queue is Full\n");
        return;
    }
    lqueue[ ++rear ] = input;
}

int deque()
{
    if ( (front > rear ) || ( rear  == -1) )
    {
        printf("Queue is empty\n");
        return 0;
    }
    return lqueue[ front++];
}


void display()
{
    int i;
    if ( (front > rear ) || ( rear  == -1))
    {
        printf("Queue is empty\n");
        return;
    }
    for( i=front ; i<=rear  ;i++)
    {
        printf("|%d|",lqueue[i]);
    }
}

main()
{
    int input,delete,choice;
    for(;;)
    {
        printf("Enter 1 for insertion/ 2 for deletion / 3 to display elmts of queue\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter number that needs to be inserted:\n");
                     scanf("%d",&input);
                     enque(input);
                     break;
            case 2 : delete = deque();
                     if( delete != 0)
                     printf("%d is deleted now front=%d and rear=%d\n",delete,front,rear );
                     break;
            case 3 : display();
                     break;
            default : printf("Invalid choice\n");
                      exit(0);

        }
    }
}