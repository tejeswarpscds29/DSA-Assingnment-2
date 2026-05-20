// 4. Printer Queue Simulation

#include <stdio.h>
#include <string.h>

#define MAX 5

char queue[MAX][20];
int front = -1, rear = -1;

void addDocument(char doc[])
{
    if(rear == MAX - 1)
    {
        printf("Queue Full\n");
        return;
    }

    if(front == -1)
        front = 0;

    rear++;
    strcpy(queue[rear], doc);

    printf("Document Added\n");
}

void printDocument()
{
    if(front == -1 || front > rear)
    {
        printf("No Documents\n");
        return;
    }

    printf("Printing: %s\n", queue[front]);
    front++;
}

void display()
{
    int i;

    if(front == -1 || front > rear)
    {
        printf("No Pending Documents\n");
        return;
    }

    printf("Pending Documents:\n");

    for(i = front; i <= rear; i++)
    {
        printf("%s\n", queue[i]);
    }
}

int main()
{
    int choice;
    char doc[20];

    while(1)
    {
        printf("\n1.Add Document\n2.Print Document\n3.Display\n4.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Document Name: ");
                scanf("%s", doc);
                addDocument(doc);
                break;

            case 2:
                printDocument();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}