//~ Explanation of the code:
//^                         https://chat.openai.com/share/223f5198-df54-4838-8072-5f517c7a2d52

// Array implimentation of Circular Queue Data Structure.

#include <stdio.h>
#include <stdlib.h>

//====================================================================| FUNCTION DECLARATION |==============================================================

void cir_enqueue();
void cir_display();
void cir_dequeue();

struct node
{
    int data;
    struct node *next;
};

struct node *front;
struct node *rear;

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

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if ((front == NULL) && (rear == NULL))
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        newnode->next = front;
    }
    printf("Enqueue Operation Succeefull.\n");
}

//====================================================================| DISPLAY FUNCTION |===================================================================

void cir_display()
{
    printf("\nDISPLAY OPERATION:\n");
    struct node *ptr;
    // ptr = front;
    if ((front == NULL) && (rear == NULL))
    {
        printf("Queue is Empty.");
    }
    else
    {
        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != front);
    }
    printf("\n");
}

//====================================================================| DEQUEUE FUNCTION |===================================================================

void cir_dequeue()
{
    printf("\nDEQUEUE OPERATION:\n");
    struct node *ptr;
    ptr = front;
    if ((front == NULL) && (rear == NULL))
    {
        printf("Queue is Empty.\n");
    }
    else if (front == rear)
    {
        printf("The Dequeued element is: %d\n", ptr->data);
        front = rear = NULL;
        free(ptr);
        printf("Dequeue Operation Successful.\n");
    }
    else
    {
        printf("The Dequeued element is: %d\n", ptr->data);
        front = front->next;
        rear->next = front;
        free(ptr);
        printf("Dequeue Operation Successful.\n");
    }
}