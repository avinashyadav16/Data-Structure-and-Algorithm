// // Linked List implimentation of stack data structure. ( with void return type )





// #include <stdio.h>
// #include <stdlib.h>

// //===================================================================| FUNCTION DECLARATION |================================================================

// void push();
// void display();
// void pop();
// void peek();

// struct node
// {
//     int data;
//     struct node *next;
// };

// struct node *head = NULL;

// //========================================================================| MAIN FUNCTION |==================================================================

// int main()
// {
//     int choice, num_operation;
//     printf("\n");
//     printf("\t\t\t\t1.  Push Operation\n");
//     printf("\t\t\t\t2.  Display Operation\n");
//     printf("\t\t\t\t3.  Pop Operation\n");
//     printf("\t\t\t\t4.  Top Operation\n");
//     printf("\t\t\t\t5.  Exit\n\n");

//     printf("Enter Number of times to perform operations: ");
//     scanf("%d", &num_operation);

//     for (int i = 1; i <= num_operation; i++)
//     {
//         printf("\nEnter Operation Choice(1-5): ");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//             push();
//             break;

//         case 2:
//             display();
//             break;

//         case 3:
//             pop();
//             break;

//         case 4:
//             peek();
//             break;

//         case 5:
//             printf("\t\t\t\t\tExiting From the Code\n\n");
//             return 0;

//         default:
//             printf("\t\t\t\t** Invalid Input Given by the User **\n");
//             printf("\t\t\t\t\tEnter the correct input");
//             break;
//         }
//     }
//     return 0;
// }

// //======================================================================| PUSH OPERATION |===================================================================

// void push()
// {
//     printf("\nSTACK PUSH OPERATION:\n");
//     struct node *newnode;
//     newnode = (struct node *)malloc(sizeof(struct node));
//     if (newnode == NULL)
//     {
//         printf("Stack Overflow.\n");
//         return;
//     }
//     if (head == NULL)
//     {
//         printf("Enter the first value: ");
//         scanf("%d", &newnode->data);
//         newnode->next = NULL;
//         head = newnode;
//     }
//     else
//     {
//         printf("Enter the value in the stack: ");
//         scanf("%d", &newnode->data);
//         newnode->next = head;
//         head = newnode;
//     }
//     printf("Stack Push Operation Successful\n");
// }

// //======================================================================| DISPLAY OPERATION |================================================================

// void display()
// {
//     printf("\nSTACK DISPLAY OPERATION:\n");
//     struct node *ptr = head;
//     if (ptr == NULL)
//     {
//         printf("Stack Underflow. No element to display\n");
//         return;
//     }
//     while (ptr != NULL)
//     {
//         printf("%d ", ptr->data);
//         ptr = ptr->next;
//     }
//     printf("\n");
// }

// //======================================================================| POP OPERATION |===================================================================

// void pop()
// {
//     printf("\nSTACK POP OPERATION:\n");
//     struct node *ptr = head;
//     if (ptr == NULL)
//     {
//         printf("Stack Underflow. Pop Operation can't be performed\n");
//         return;
//     }
//     else
//     {
//         printf("Popped Element is: %d", ptr->data);
//         head = ptr->next;
//         free(ptr);
//     }
//     printf("\n");
// }

// //======================================================================| PEEK OPERATION |===================================================================

// void peek()
// {
//     printf("\nSTACK PEEK OPERATION:\n");
//     struct node *ptr = head;
//     if (ptr == NULL)
//     {
//         printf("Stack Underflow. No top value can be Displayed\n");
//         return;
//     }
//     else
//     {
//         printf("The top element is: %d", head->data);
//     }
//     printf("\n");
// }














// Linked List implimentation of stack data structure. ( with return type )

#include <stdio.h>
#include <stdlib.h>

//===================================================================| FUNCTION DECLARATION |================================================================

struct node *push();
void display(struct node*);
struct node *pop(struct node*);
void peek(struct node*);

struct node
{
    int data;
    struct node *next;
};

struct node *top;

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
            top = push();
            break;

        case 2:
            display(top);
            break;

        case 3:
            top = pop(top);
            break;

        case 4:
            peek(top);
            break;

        case 5:
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

//======================================================================| PUSH OPERATION |===================================================================

struct node *push()
{
    printf("\nSTACK PUSH OPERATION:\n");
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Stack Overflow.\n");
        return newnode;
    }
    if (top == NULL)
    {
        printf("Enter the first value: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        top = newnode;
    }
    else
    {
        printf("Enter the value in the stack: ");
        scanf("%d", &newnode->data);
        newnode->next = top;
        top = newnode;
    }
    printf("Stack Push Operation Successful.\n");
    return top;
}

//======================================================================| DISPLAY OPERATION |================================================================

void display(struct node *top)
{
    printf("\nSTACK DISPLAY OPERATION:\n");
    struct node *ptr = top;
    if (ptr == NULL)
    {
        printf("Stack Underflow. No element to display.\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

//======================================================================| POP OPERATION |===================================================================

struct node *pop(struct node *top)
{
    printf("\nSTACK POP OPERATION:\n");
    struct node *ptr = top;
    if (ptr == NULL)
    {
        printf("Stack Underflow. Pop Operation can't be performed.\n");
        return top;
    }
    else
    {
        printf("Popped Element is: %d", ptr->data);
        top = ptr->next;
        free(ptr);
    }
    printf("\n");
    return top;
}

//======================================================================| PEEK OPERATION |===================================================================

void peek(struct node *top)
{
    printf("\nSTACK PEEK OPERATION:\n");
    struct node *ptr = top;
    if (ptr == NULL)
    {
        printf("Stack Underflow. No top value can be Displayed.\n");
        return;
    }
    else
    {
        printf("The top element is: %d", top->data);
    }
    printf("\n");
}