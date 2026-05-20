// 5. Circular Queue Operations

#include <stdio.h>

#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if((rear + 1) % MAX == front)
    {
        printf("Queue Full\n");
        return;
    }

    if(front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    cq[rear] = value;

    printf("Inserted\n");
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("Deleted Element: %d\n", cq[front]);

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void peek()
{
    if(front == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("Front Element: %d\n", cq[front]);
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("Queue Elements:\n");

    i = front;

    while(i != rear)
    {
        printf("%d ", cq[i]);
        i = (i + 1) % MAX;
    }

    printf("%d", cq[rear]);
}

int main()
{
    int choice, value;

    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}