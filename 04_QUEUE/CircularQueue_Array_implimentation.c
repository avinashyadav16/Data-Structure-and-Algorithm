// Array implimentation of Circular Queue Data Structure.

#include <stdio.h>

//=====================================================================| GLOBAL DECLARATION |===============================================================

#define size 6
int cir_queue[size];
int front = -1, rear = -1;

//====================================================================| FUNCTION DECLARATION |==============================================================

void cir_enqueue();
void cir_display();
void cir_dequeue();

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
            cir_enqueue();
            break;

        case 2:
            cir_display();
            break;

        case 3:
            cir_dequeue();
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

//====================================================================| ENQUEUE FUNCTION |===================================================================

void cir_enqueue()
{
    printf("\nENQUEUE OPERATION:\n");
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);

    if ((rear + 1) % size == front)
    {
        printf("Circular Queue is full.\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        cir_queue[rear] = value;
        printf("Enqueue Operation Succeefull.\n");
    }
}

//====================================================================| DISPLAY FUNCTION |===================================================================

void cir_display()
{
    printf("\nDISPLAY OPERATION:\n");
    if (front == -1)
    {
        printf("Circular Queue is empty.");
    }
    else
    {
        for (int i = front; i != (rear + 1) % size; i = (i + 1) % size)
        {
            printf("%d ", cir_queue[i]);
        }
    }
    printf("\n");
}

//====================================================================| DEQUEUE FUNCTION |===================================================================

void cir_dequeue()
{
    printf("\nDEQUEUE OPERATION:\n");
    if (front == -1)
    {
        printf("Circular Queue is empty.");
    }
    else
    {
        printf("Dequeue Operation Successful.\n");
        printf("The Dequeued element is: %d\n", cir_queue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
    printf("\n");
}