#include <stdio.h>
#include <stdlib.h>

//==============================================================| FUNCTION DECLARATION |======================================================================

struct node *create_SLL(int);
void display_SLL(struct node *head);
void dis_rev_SLL(struct node *head);

struct node
{
    int data;
    struct node *next;
};
struct node *head;

//==============================================================| MAIN FUNCTION |=============================================================================

int main()
{
    int n;
    printf("Enter the number of elements in the list - ");
    scanf("%d", &n);
    head = create_SLL(n);
    display_SLL(head);
    dis_rev_SLL(head);
    return 0;
}

//==============================================================| CREATING LINKED LINK |======================================================================

struct node *create_SLL(int n)
{
    int i;
    struct node *ptr;
    for (i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            head = (struct node *)malloc(sizeof(struct node));
            ptr = head;
        }
        else
        {
            ptr->next = (struct node *)malloc(sizeof(struct node));
            ptr = ptr->next;
        }
        printf("Enter the element_%d = ", i);
        scanf("%d", &ptr->data);
    }
    ptr->next = NULL;
    printf("\n");
    return head;
}

//==============================================================| DISPLAYING THE LINKED LIST ELEMENTS |=======================================================

void display_SLL(struct node *head)
{
    struct node *ptr;
    printf("Elements in the SLL are: ");
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%d  ", ptr->data);
    }
    printf("\n\n");
}

void dis_rev_SLL(struct node *head)
{
    struct node *pre_node, *cur_node;

    if (head != NULL)
    {
        pre_node = head;
        cur_node = head -> next;
        head = head -> next;

        pre_node -> next = NULL; // Make first node as last node

        while (head != NULL)
        {
            head = head -> next;
            cur_node -> next = pre_node;

            pre_node = cur_node;
            cur_node = head;
        }

        head = pre_node; // Make last node as head
        display_SLL(head);
        printf("SUCCESSFULLY REVERSED LIST\n");
    }
}
