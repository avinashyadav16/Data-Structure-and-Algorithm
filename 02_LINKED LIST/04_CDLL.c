#include <stdio.h>
#include <stdlib.h>

//===================================================================| FUNCTION DECLARATION |================================================================

struct node *create_CDLL(int);                     // FUNCTION DECLERATION -   01
void display_CDLL(struct node *head);              // FUNCTION DECLERATION -   02
void search_CDLL(struct node *head);               // FUNCTION DECLERATION -   03
struct node *insert_big_CDLL(struct node *head);   // FUNCTION DECLERATION -   04
struct node *insert_bfloc_CDLL(struct node *head); // FUNCTION DECLERATION -   05
struct node *insert_afloc_CDLL(struct node *head); // FUNCTION DECLERATION -   06
struct node *insert_bfkey_CDLL(struct node *head); // FUNCTION DECLERATION -   07
struct node *insert_afkey_CDLL(struct node *head); // FUNCTION DECLERATION -   08
struct node *insert_end_CDLL(struct node *head);   // FUNCTION DECLERATION -   09
struct node *del_big_CDLL(struct node *head);      // FUNCTION DECLERATION -   10
struct node *del_bfloc_CDLL(struct node *head);    // FUNCTION DECLERATION -   11
struct node *del_afloc_CDLL(struct node *head);    // FUNCTION DECLERATION -   12
struct node *del_key_CDLL(struct node *head);      // FUNCTION DECLERATION -   13
struct node *del_end_CDLL(struct node *head);      // FUNCTION DECLERATION -   14

struct node
{
    struct node *Lnext;
    int data;
    struct node *Rnext;
};
struct node *head;

//========================================================================| MAIN FUNCTION |==================================================================

int main()
{
    printf("\t\t\t\t1.  CREATE A CDLL\n");
    printf("\t\t\t\t2.  DISPLAY CDLL\n");
    printf("\t\t\t\t3.  SEARCH IN CDLL\n");
    printf("\t\t\t\t4.  INSERT AT THE BEGINNING\n");
    printf("\t\t\t\t5.  INSERT BEFORE A GIVEN LOCATION\n");
    printf("\t\t\t\t6.  INSERT AFTER A GIVEN LOCATION\n");
    printf("\t\t\t\t7.  INSERT BEFORE A GIVEN KEY\n");
    printf("\t\t\t\t8.  INSERT AFTER A GIVEN KEY\n");
    printf("\t\t\t\t9.  INSERT AT THE END\n");
    printf("\t\t\t\t10. DELETE AT THE BEGINNING\n");
    printf("\t\t\t\t11. DELETE BEFORE A GIVEN LOCATION\n");
    printf("\t\t\t\t12. DELETE AFTER A GIVEN LOCATION\n");
    printf("\t\t\t\t13. DELETE A GIVEN KEY\n");
    printf("\t\t\t\t14. DELETE AT THE END\n");
    printf("\t\t\t\t15. EXIT\n\n");
    int runtime, choice, size;
    printf("How many operations you want to perform: ");
    scanf("%d", &runtime);
    printf("\n");

    for (int i = 0; i < runtime; i++)
    {
        printf("\nEnter the operation choice(1-14): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nCREATING CDLL:\n");
            printf("Enter the number of nodes in the CDLL: ");
            scanf("%d", &size);
            head = create_CDLL(size);
            break;

        case 2:
            display_CDLL(head);
            break;

        case 3:
            search_CDLL(head);
            break;

        case 4:
            head = insert_big_CDLL(head);
            display_CDLL(head);
            break;

        case 5:
            head = insert_bfloc_CDLL(head);
            display_CDLL(head);
            break;

        case 6:
            head = insert_afloc_CDLL(head);
            display_CDLL(head);
            break;

        case 7:
            head = insert_bfkey_CDLL(head);
            display_CDLL(head);
            break;

        case 8:
            head = insert_afkey_CDLL(head);
            display_CDLL(head);
            break;

        case 9:
            head = insert_end_CDLL(head);
            display_CDLL(head);
            break;

        case 10:
            head = del_big_CDLL(head);
            display_CDLL(head);
            break;

        case 11:
            head = del_bfloc_CDLL(head);
            display_CDLL(head);
            break;

        case 12:
            head = del_afloc_CDLL(head);
            display_CDLL(head);
            break;

        case 13:
            head = del_key_CDLL(head);
            display_CDLL(head);
            break;

        case 14:
            head = del_end_CDLL(head);
            display_CDLL(head);
            break;

        case 15:
            printf("\n");
            printf("\t\t\t\t!!  THANK YOU   !!\n");
            printf("\t\t\t     YOU EXISTED FROM THE CODE\n\n");
            return 0;

        default:
            printf("\t\t\t\t** Invalid Input Given by the User **\n");
            printf("\t\t\t\t\tEnter the correct input");
            break;
        }
    }

    return 0;
}

//==============================================================| CREATING CIRCULARLY DOUBLY LINKED LINK |=====================================================================

struct node *create_CDLL(int n)
{
    int i;
    struct node *newnode, *ptr;
    for (i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            head = (struct node *)malloc(sizeof(struct node));
            head->Lnext = NULL;
            ptr = head;
        }
        else
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            ptr->Rnext = newnode;
            newnode->Lnext = ptr;
            ptr = newnode;
        }
        printf("Enter Node_%d - ", i);
        scanf("%d", &ptr->data);
    }
    ptr->Rnext = head;
    head->Lnext = ptr;
    return head;
}

//==============================================================| DISPLAYING THE CDLL ELEMENTS |==============================================================

void display_CDLL(struct node *head)
{
    printf("\nDISPLAYING CDLL\n");
    printf("CDLL elements are:  ");
    struct node *ptr;
    ptr = head;

    printf("%d ", ptr->data);
    ptr = ptr->Rnext;

    while (ptr != head)
    {
        printf("%d ", ptr->data);
        ptr = ptr->Rnext;
    }
    printf("\n");
}

//==============================================================| SEARCHING ELEMENTS IN CDLL |================================================================

void search_CDLL(struct node *head)
{
    printf("SEARCHING CLL\n");
    struct node *ptr;
    int value, flag = 0;
    printf("Enter an Element to search - ");
    scanf("%d", &value);
    ptr = head;
    while (ptr->Rnext != head)
    {
        if (ptr->data == value)
        {
            flag = 1;
            break;
        }
        ptr = ptr->Rnext;
    }
    if (flag == 1)
        printf("Result - %d Found in the CLL.\n\n", value);
    else
        printf("Result - %d not found in the CLL.\n\n", value);
}

//==============================================================| INSERTING ELEMENT AT THE BEGININNG |=======================================================

struct node *insert_big_CDLL(struct node *head)
{
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be inserted at the beginning: ");
    scanf("%d", &newnode->data);
    ptr = head;
    while (ptr->Rnext != head)
    {
        ptr = ptr->Rnext;
    }
    newnode->Lnext = ptr;
    ptr->Rnext = newnode;
    newnode->Rnext = head;
    head->Lnext = newnode;
    head = newnode;
    return (head);
}

//==============================================================| INSERTING ELEMENT BEFORE A LOCATION |=====================================================

struct node *insert_bfloc_CDLL(struct node *head)
{
    printf("\nINSERTING BEFORE A LOCATION\n");
    int loc, count = 1;
    printf("Enter location before which you want to insert: ");
    scanf("%d", &loc);

    struct node *newnode, *ptr;
    struct node *prev = NULL;
    ptr = head;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element: ");
    scanf("%d", &newnode->data);

    if (loc == 1)
    {
        newnode->Rnext = ptr;
        while (ptr->Rnext != head)
        {
            ptr = ptr->Rnext;
        }
        newnode->Lnext = ptr->Rnext;
        ptr->Rnext = newnode;
        head = newnode;
        return head;
    }

    else
    {
        while (ptr->Rnext != head && count < loc)
        {
            prev = ptr;
            ptr = ptr->Rnext;
            count++;
        }
        newnode->Lnext = prev->Rnext;
        newnode->Rnext = ptr;
        prev->Rnext = newnode;
        ptr->Lnext = newnode;
        return head;
    }
}

//==============================================================| INSERTING ELEMENT AFTER A LOCATION |=======================================================

struct node *insert_afloc_CDLL(struct node *head)
{
    printf("\nINSERTING AFTER A LOCATION\n");
    int loc, count = 0;
    printf("Enter location after which you want to insert: ");
    scanf("%d", &loc);

    struct node *newnode, *ptr;
    struct node *prev = NULL;
    ptr = head;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = newnode;
        head->Lnext = head->Rnext = head;
        return head;
    }

    while (ptr->Rnext != head && count < loc)
    {
        prev = ptr;
        ptr = ptr->Rnext;
        count++;
    }

    if (ptr->Rnext == head)
    {
        newnode->Lnext = ptr;
        ptr->Rnext = newnode;
        newnode->Rnext = head;
        head->Lnext = newnode;
        return head;
    }

    newnode->Lnext = prev;
    newnode->Rnext = ptr;
    ptr->Lnext = newnode;
    prev->Rnext = newnode;
    return head;
}

//==============================================================| INSERTING ELEMENT BEFORE AN KEY|===========================================================

struct node *insert_bfkey_CDLL(struct node *head)
{
}

//==============================================================| INSERTING ELEMENT AFTER AN KEY|============================================================

struct node *insert_afkey_CDLL(struct node *head)
{
}

//==============================================================| INSERTING ELEMENT AT THE END |=============================================================

struct node *insert_end_CDLL(struct node *head)
{
    printf("\nINSERTING ELEMENT AT THE END\n");

    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    ptr = head;

    printf("Enter the element to insert at the end - ");
    scanf("%d", &newnode->data);

    while (ptr->Rnext != head)
    {
        ptr = ptr->Rnext;
    }

    ptr->Rnext = newnode;
    newnode->Lnext = ptr;
    head->Lnext = newnode; // Update the previous node's Lnext pointer
    newnode->Rnext = head; // Update the new node's Rnext pointer to make it circular
    return head;
}

//==============================================================| DELETING ELEMENT FROM BEGINNING |==========================================================

struct node *del_big_CDLL(struct node *head)
{
    printf("\nDELETING ELEMENT AT THE BEGINNING\n");

    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    if (head->Rnext == head)
    {
        free(head);
        return NULL;
    }

    struct node *ptr = head;
    while (ptr->Rnext != head)
    {
        ptr = ptr->Rnext;
    }

    ptr->Rnext = head->Rnext;
    head = head->Rnext;
    head->Lnext = ptr;
    free(ptr);
    return head;
}

//==============================================================| DELETING ELEMENT BEFORE A LOCATION |======================================================

struct node *del_bfloc_CDLL(struct node *head)
{
    int location, count = 0;
    struct node *ptr, *prev, *temp;

    if (head == NULL)
    {
        printf("The list is empty\n");
        return head;
    }

    printf("Enter the location before which you want to delete the element: ");
    scanf("%d", &location);

    ptr = head;

    // Traverse to the node before the specified location
    while (ptr->Rnext != head && count < (location - 1))
    {
        prev = ptr;
        ptr = ptr->Rnext;
        count++;
    }

    if (count != (location - 1) || ptr->Rnext == head)
    {
        printf("Invalid location\n");
        return head;
    }

    // Delete the node before the specified location
    temp = prev->Rnext; // Node to be deleted
    prev->Rnext = ptr->Rnext;
    ptr = ptr->Rnext;
    ptr->Lnext = prev;
    free(temp); // Free the memory

    return head;
}

//==============================================================| DELETING ELEMENT AFTER A LOCATION |========================================================

struct node *del_afloc_CDLL(struct node *head)
{
    int location, count = 1;
    struct node *ptr, *prev, *temp;

    if (head == NULL)
    {
        printf("The list is empty\n");
        return head;
    }

    printf("Enter the location after which you want to delete the element: ");
    scanf("%d", &location);

    ptr = head;

    while (ptr->Rnext != head && count < location)
    {
        ptr = ptr->Rnext;
        count++;
    }

    if (count < location)
    {
        printf("Invalid location\n");
        return head;
    }

    temp = ptr->Rnext;
    ptr->Rnext = temp->Rnext;
    prev = temp->Rnext;
    prev->Lnext = ptr;
    free(temp);
    return head;
}

//==============================================================| DELETING A GIVEN KEY IN THE CDLL |==========================================================

struct node *del_key_CDLL(struct node *head)
{
    printf("DELETING A GIVEN KEY\n");
    struct node *ptr, *prev, *temp;
    int key;
    printf("Enter key to be deleted: ");
    scanf("%d", &key);
    ptr = head;
    prev = NULL;

    if (head == NULL)
    {
        printf("The CDLL is empty.\n");
        return head;
    }

    if (ptr->data == key)
    {
        prev = ptr->Lnext;
        head = ptr->Rnext;
        prev->Rnext = head;
        head->Lnext = prev;
        free(ptr);
        printf("The key has successfully been deleted.\n");
        return head;
    }

    else
    {
        ptr = ptr->Rnext;
        while (ptr != head && ptr->data != key)
        {
            prev = ptr;
            ptr = ptr->Rnext;
        }
        if (ptr == head)
        {
            printf("The key is not found.\n");
            return head;
        }
        prev->Rnext = ptr->Rnext;
        temp = ptr;
        ptr = ptr->Rnext;
        ptr->Lnext = prev;
        free(temp);
        printf("The key has successfully been deleted.\n");
        return head;
    }
}

//==============================================================| DELETING ELEMENT AT THE END OF THE CDLL |===================================================

struct node *del_end_CDLL(struct node *head)
{
    struct node *temp, *prev;

    if (head == NULL)
    {
        printf("The list is empty\n");
        return head;
    }

    // If there is only one node in the list
    if (head->Rnext == head)
    {
        free(head);
        head = NULL;
        return head;
    }

    // Traverse to the last node of the list
    prev = head;
    temp = head->Rnext;
    while (temp->Rnext != head)
    {
        prev = temp;
        temp = temp->Rnext;
    }

    // Delete the last node and update the links
    prev->Rnext = head;
    head->Lnext = prev;
    free(temp);

    return head;
}