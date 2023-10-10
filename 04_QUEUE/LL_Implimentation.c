
// Linked List implimentation of stack data structure.

#include <stdio.h>
#include <stdlib.h>

//===================================================================| FUNCTION DECLARATION |================================================================
struct node *enqueue();
void display();
struct node *dequeue();

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

//========================================================================| MAIN FUNCTION |==================================================================

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
        printf("\nEnter Operation Choice(1-5): ");
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
            printf("\t\t\t\t\tExiting From the Code\n\n");
            return 0;

        default:
            printf("\t\t\t\t** Invalid Input Given by the User **\n");
            printf("\t\t\t\t\tEnter the correct input");
            break;
        }
    }
    return 0;
}

//======================================================================| ENQUEUE OPERATION |================================================================

struct node *enqueue()
{
    printf("\nENQUEUE OPERATION:\n");
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);

    struct node *ptr;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if ((front == NULL) && (rear == NULL))
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Node has been inserted successfully inserted.\n\n");
    return rear;
}

//======================================================================| DISPLAY OPERATION |================================================================

void display()
{
    printf("\nQUEUE DISPLAY OPERATION:\n");
    if (front == NULL)
    {
        printf("\nQueue is Underflow.\nNo element to display.\n");
        return;
    }

    struct node *ptr;
    for (ptr = front; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ", ptr->data);
    }
    printf("\n");
}

//======================================================================| DEQUEUE OPERATION |================================================================

struct node *dequeue()
{
    printf("\nDEQUEUE OPERATION:\n");

    if (front == NULL)
    {
        printf("\nQueue is Underflow.\n");
        return front;
    }

    else
    {
        struct node *temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
        printf("Dequeue Operation Successful.\n");
        printf("Dequeued element is: %d", temp_data);
    }
    printf("\n");
    return front;
}