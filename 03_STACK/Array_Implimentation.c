// Array implimentation of stack data structure.

#include <stdio.h>
#include <stdlib.h>

//======================================================================| GLOBAL DECLARATION |===================================================================

#define max 10
int stack[max];
int top = -1;

//===================================================================| FUNCTION DECLARATION |================================================================

void push();
void display();
void pop();
void peek();

//========================================================================| MAIN FUNCTION |==================================================================

int main()
{
    int choice, num_operation;
    printf("\n");
    printf("\t\t\t\t1.  Push Operation\n");
    printf("\t\t\t\t2.  Display Operation\n");
    printf("\t\t\t\t3.  Pop Operation\n");
    printf("\t\t\t\t4.  Top Operation\n");
    printf("\t\t\t\t5.  Exit\n\n");

    printf("Enter Number of times to perform operations: ");
    scanf("%d", &num_operation);

    for (int i = 1; i <= num_operation; i++)
    {
        printf("\nEnter Operation Choice(1-5): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            display();
            break;

        case 3:
            pop();
            break;

        case 4:
            peek();
            break;

        case 5:
            printf("\t\t\t\tExiting From the Code\n\n");
            return 0;

        default:
            printf("\t\t\t\t** Invalid Input Given by the User **\n");
            printf("\t\t\t\t\tEnter the correct input");
            break;
        }
    }
    return 0;
}

//======================================================================| PUSH OPERATION |===================================================================

void push()
{
    int data;
    printf("Enter the value: ");
    scanf("%d", &data);

    if (top == (max - 1))
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        top++;
        stack[top] = data;
    }
}

//======================================================================| DISPLAY OPERATION |================================================================

void display()
{
    if (top == -1)
    {
        printf("Stack is Empty.\n");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

//======================================================================| POP OPERATION |===================================================================

void pop()
{
    int popped_item;
    if (top == -1)
    {
        printf("Stack is Empty.\n");
        return;
    }
    else
    {
        popped_item = stack[top];
        top--;
        printf("Popped element is: %d\n", popped_item);
    }
    return;
}

//======================================================================| PEEK OPERATION |===================================================================

void peek()
{
    printf("The Top element is: %d\n", stack[top]);
}
