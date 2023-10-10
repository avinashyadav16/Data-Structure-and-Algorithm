// Array implimentation of Queue Data Structure.

#include <stdio.h>

//=====================================================================| GLOBAL DECLARATION |===============================================================

#define max 3
int queue[max];
int front = -1, rear = -1;

//====================================================================| FUNCTION DECLARATION |==============================================================

void enqueue();
void display();
void dequeue();

//======================================================================| MAIN FUNCTION |===================================================================

int main()
{
    int choice, num_operation;
    printf("\n");
    printf("\t\t\t\t1.  Enqueue Operation\n");
    printf("\t\t\t\t2.  Display Operation\n");
    printf("\t\t\t\t3.  Dequeue Operation\n");
    printf("\t\t\t\t4.  Exit\n\n");

    printf("Enter Number of times to perform operations: ");
    scanf("%d", &num_operation);

    for (int i = 1; i <= num_operation; i++)
    {
        printf("\nEnter Operation Choice(1-4): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            display();
            break;

        case 3:
            dequeue();
            break;

        case 4:
            printf("\t\t\t\t\tExisted From the Code\n\n");
            return 0;

        default:
            printf("\t\t\t\t** Invalid Input Given by the User **\n");
            printf("\t\t\t\t\tEnter the correct input");
            break;
        }
    }
    return 0;
}

//========================================================================| ENQUEUE OPERATION |==============================================================

void enqueue()
{
    printf("\nENQUEUE OPERATION:\n");
    int value;

    if (rear == (max - 1))
    {
        printf("Queue is full.\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &value);

    if (rear == -1 && front == -1)
    {
        rear++;
        front++;
        queue[rear] = value;
    }
    else
    {
        rear++;
        queue[rear] = value;
    }
    printf("Enqueue Operation Succeefull.\n");
}

//========================================================================| DISPLAY OPERATION |==============================================================

void display()
{
    printf("\nDISPLAY OPERATION:\n");

    if (front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    else if (front == (max))
    {
        printf("Queue is full. Front has reached to the end.\n");
        return;
    }

    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

//========================================================================| DEQUEUE OPERATION |==============================================================

void dequeue()
{
    printf("\nDEQUEUE OPERATION:\n");
    int removed_element;

    if ((front == -1 && rear == -1) || front == max)
    {
        if(front == -1 && rear == -1)
        {
            printf("Queue is empty.\n");
            return;
        }
        else
        {
            printf("Queue is full. Front has reached to the end.\n");
            return;
        }
    }
    
    removed_element = queue[front];
    front++;
    printf("Removed Element is: %d",removed_element);
    printf("\nDequeue Operation Succeefull.\n");
}
