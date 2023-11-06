#include<stdio.h>
#include<stdlib.h>
#define size 5

int cqueue[size],front = 0, rear = -1,count = 0;

void enque(int input)
{
    if( count == size)
    {
        printf("Queue is full\n");
        return;
    }
    rear = (rear + 1) % size;
    cqueue[ rear] = input;
    count ++;
}

void deque()
{
    if( count == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d is deleted \n", cqueue[front]);
    front = (front + 1) % size;
    count --;
}

void display()
{
    if( count == 0)
    {
        printf("Queue is empty\n");
    }
    int i,temp = front;
    for(i=0; i<count; i++)
    {
        printf(" %d = |%d|",temp,cqueue[ temp]);
        temp = (temp + 1) % size;
    }
    printf("\n");
}

main()
{
    int input , choice , delete;
    printf("Enter an operation that needs to be performed:\n");
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
            case 2 : deque();
                     break;
            case 3 : display();
                     break;
            default : printf("Invalid choice\n");
                      exit(0);

    }
}
}