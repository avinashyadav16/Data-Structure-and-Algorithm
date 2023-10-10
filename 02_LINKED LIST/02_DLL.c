#include <stdio.h>
#include <stdlib.h>

//===================================================================| FUNCTION DECLARATION |================================================================

struct node *create_DLL(int);                     // FUNCTION DECLERATION -   01
void display_DLL(struct node *head);              // FUNCTION DECLERATION -   02
void search_DLL(struct node *head);               // FUNCTION DECLERATION -   03
struct node *insert_big_DLL(struct node *head);   // FUNCTION DECLERATION -   04
struct node *insert_bfloc_DLL(struct node *head); // FUNCTION DECLERATION -   05
struct node *insert_afloc_DLL(struct node *head); // FUNCTION DECLERATION -   06
struct node *insert_bfkey_DLL(struct node *head); // FUNCTION DECLERATION -   07
struct node *insert_afkey_DLL(struct node *head); // FUNCTION DECLERATION -   08
struct node *insert_end_DLL(struct node *head);   // FUNCTION DECLERATION -   09
struct node *del_big_DLL(struct node *head);      // FUNCTION DECLERATION -   10
struct node *del_bfloc_DLL(struct node *head);    // FUNCTION DECLERATION -   11
struct node *del_afloc_DLL(struct node *head);    // FUNCTION DECLERATION -   12
struct node *del_key_DLL(struct node *head);      // FUNCTION DECLERATION -   13
struct node *del_end_DLL(struct node *head);      // FUNCTION DECLERATION -   14

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
    printf("\t\t\t\t1.  CREATE A DLL\n");
    printf("\t\t\t\t2.  DISPLAY DLL\n");
    printf("\t\t\t\t3.  SEARCH IN DLL\n");
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
            printf("\nCREATING DLL:\n");
            printf("Enter the number of nodes in the DLL: ");
            scanf("%d", &size);
            head = create_DLL(size);
            break;

        case 2:
            display_DLL(head);
            break;

        case 3:
            search_DLL(head);
            break;

        case 4:
            head = insert_big_DLL(head);
            display_DLL(head);
            break;

        case 5:
            head = insert_bfloc_DLL(head);
            display_DLL(head);
            break;

        case 6:
            head = insert_afloc_DLL(head);
            display_DLL(head);
            break;

        case 7:
            head = insert_bfkey_DLL(head);
            display_DLL(head);
            break;

        case 8:
            head = insert_afkey_DLL(head);
            display_DLL(head);
            break;

        case 9:
            head = insert_end_DLL(head);
            display_DLL(head);
            break;

        case 10:
            head = del_big_DLL(head);
            display_DLL(head);
            break;

        case 11:
            head = del_bfloc_DLL(head);
            display_DLL(head);
            break;

        case 12:
            head = del_afloc_DLL(head);
            display_DLL(head);
            break;

        case 13:
            head = del_key_DLL(head);
            display_DLL(head);
            break;

        case 14:
            head = del_end_DLL(head);
            display_DLL(head);
            break;

        case 15:
            printf("\n");
            printf("\t\t\t\t!!  THANK YOU   !!\n");
            printf("\t\t\t     YOU EXISTED FROM THE CODE\n\n");
            break;

        default:
            printf("\t\t\t\t** Invalid Input Given by the User **\n");
            printf("\t\t\t\t\tEnter the correct input");
            break;
        }
    }

    return 0;
}

//==============================================================| CREATING DOUBLY LINKED LINK |=====================================================================

struct node *create_DLL(int n)
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
    ptr->Rnext = NULL;
    return head;
}

//==============================================================| DISPLAYING THE DLL ELEMENTS |==============================================================

void display_DLL(struct node *head)
{
    printf("\nDISPLAYING DLL\n");
    printf("DLL elements are:  ");
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->Rnext;
    }
    printf("\n");
}

//==============================================================| SEARCHING ELEMENTS IN DLL |================================================================

void search_DLL(struct node *head)
{
    printf("\nSEARCHING IN DLL\n");
    int num, flag = 0;
    struct node *ptr;
    ptr = head;
    printf("Enter the element to search: ");
    scanf("%d", &num);
    while (ptr != NULL)
    {
        if (ptr->data == num)
        {
            flag = 1;
            break;
        }
        ptr = ptr->Rnext;
    }
    if (flag == 1)
    {
        printf("Result: Element %d is present in the DLL.\n", num);
    }
    else
    {
        printf("Result: Element %d is not present in the DLL.\n", num);
    }
}

//==============================================================| INSERTING ELEMENT AT THE BEGININNG |=======================================================

struct node *insert_big_DLL(struct node *head)
{
    printf("\nINSERTING AT THE BEGININNG\n");
    int num;
    struct node *newnode, *ptr;
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->Lnext = NULL;
    printf("Enter the element: ");
    scanf("%d", &newnode->data);
    ptr->Lnext = newnode;
    newnode->Rnext = ptr;
    head = newnode;
    return head;
}

//==============================================================| INSERTING ELEMENT BEFORE A LOCATION |=====================================================

struct node *insert_bfloc_DLL(struct node *head)
{
    printf("\nINSERTING BEFORE A LOCATION\n");
    int loc, count = 1;
    printf("Enter location before which you want to insert(>1): ");
    scanf("%d", &loc);
    struct node *newnode, *ptr;
    struct node *prev = NULL;
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element: ");
    scanf("%d", &newnode->data);
    while (ptr->Rnext != NULL && count != loc)
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

//==============================================================| INSERTING ELEMENT AFTER A LOCATION |=======================================================

struct node *insert_afloc_DLL(struct node *head)
{
    printf("\nINSERTING AFTER A LOCATION\n");
    int loc, count = 0;
    printf("Enter location after which you want to insert(>0): ");
    scanf("%d", &loc);
    struct node *newnode, *ptr;
    struct node *prev = NULL;
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element: ");
    scanf("%d", &newnode->data);
    while (ptr->Rnext != NULL && count != loc)
    {
        prev = ptr;
        ptr = ptr->Rnext;
        count++;
    }
    if (count < loc || loc < 1)
    {
        printf("Invalid location: You Are Trying To Insert At the Beginning/End.\n");
        return head;
    }
    newnode->Lnext = ptr->Lnext;
    newnode->Rnext = ptr;
    ptr->Lnext = newnode;
    prev->Rnext = newnode;
    return head;
}

//==============================================================| INSERTING ELEMENT BEFORE AN KEY|===========================================================

struct node *insert_bfkey_DLL(struct node *head)
{
    printf("\nINSERTING ELEMENT BEFORE A KEY\n");

    int key;
    struct node *newnode, *ptr, *prev = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    printf("Enter the element to be inserted - ");
    scanf("%d", &newnode->data);
    printf("Enter the key before which the element has to be inserted - ");
    scanf("%d", &key);

    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            newnode->Rnext = ptr;
            newnode->Lnext = ptr->Lnext;
            if (ptr->Lnext != NULL)
            {
                ptr->Lnext->Rnext = newnode;
            }
            else
            {
                head = newnode;
            }
            ptr->Lnext = newnode;
            break;
        }
        prev = ptr;
        ptr = ptr->Rnext;
    }
    if (ptr == NULL)
    {
        printf("Entered Key not found\n");
    }
    return head;
}

//==============================================================| INSERTING ELEMENT AFTER AN KEY|============================================================

struct node *insert_afkey_DLL(struct node *head)
{
    printf("\nINSERTING ELEMENT AFTER A KEY\n");

    int key;
    struct node *newnode, *ptr, *prev = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    printf("Enter the element to be inserted - ");
    scanf("%d", &newnode->data);
    printf("Enter the key after which the element has to be inserted - ");
    scanf("%d", &key);

    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            newnode->Lnext = ptr;
            newnode->Rnext = ptr->Rnext;
            if (ptr->Rnext != NULL)
            {
                ptr->Rnext->Lnext = newnode;
            }
            else
            {
                newnode->Rnext = NULL; // Inserting at the end of the list
            }
            ptr->Rnext = newnode;
            break;
        }
        prev = ptr;
        ptr = ptr->Rnext;
    }
    if (ptr == NULL)
    {
        printf("Entered Key not found\n");
    }
    return head;
}

//==============================================================| INSERTING ELEMENT AT THE END |=============================================================

struct node *insert_end_DLL(struct node *head)
{
    printf("\nINSERTING ELEMENT AT THE END\n");

    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    ptr = head;

    printf("Enter the element to insert at the end - ");
    scanf("%d", &newnode->data);

    newnode->Rnext = NULL;

    if (head == NULL)
    {
        newnode->Lnext = NULL;
        head = newnode;
        return (head);
    }

    while (ptr->Rnext != NULL)
    {
        ptr = ptr->Rnext;
    }
    ptr->Rnext = newnode;
    newnode->Lnext = ptr;
    return (head);
}

//==============================================================| DELETING ELEMENT FROM BEGINNING |==========================================================

struct node *del_big_DLL(struct node *head)
{
    printf("\nDELETING ELEMENT AT THE BEGINNING\n");
    struct node *ptr;
    if (head == NULL)
    {
        return (head);
    }
    ptr = head;
    head = head->Rnext;
    free(ptr);
    printf("The entered element has successfully been deleted.\n");
    return (head);
}

//==============================================================| DELETING ELEMENT BEFORE A LOCATION |======================================================

struct node *del_bfloc_DLL(struct node *head)
{
    printf("\nDELETING BEFORE A LOCATION\n");
    int loc, count = 1;
    printf("Enter location before which you want to delete(>1): ");
    scanf("%d", &loc);

    struct node *temp = head;
    struct node *ptr = NULL;
    struct node *prev = NULL;

    while (temp != NULL && count < loc)
    {
        prev = ptr;
        ptr = temp;
        temp = temp->Rnext;
        count++;
    }

    if (prev == NULL)
    {
        head = ptr->Rnext;
        head->Lnext = NULL;
    }
    else
    {
        prev->Rnext = ptr->Rnext;
        if (ptr->Rnext != NULL)
        {
            ptr->Rnext->Lnext = prev;
        }
    }

    free(ptr);
    return head;
}

//==============================================================| DELETING ELEMENT AFTER A LOCATION |========================================================

struct node *del_afloc_DLL(struct node *head)
{
    printf("\nDELETING BEFORE A LOCATION\n");
    int loc, count = 0;
    printf("Enter location After which you want to delete(>0): ");
    scanf("%d", &loc);

    struct node *temp = head;
    struct node *ptr = NULL;
    struct node *prev = NULL;

    while (temp != NULL && count < loc)
    {
        prev = temp;
        ptr = temp->Rnext;
        temp = temp->Rnext;
        count++;
    }

    if (ptr == NULL)
    {
        printf("Invalid location\n");
        return head;
    }

    else if (prev == NULL)
    {
        head = ptr->Rnext;
        head->Lnext = NULL;
    }
    else
    {
        prev->Rnext = ptr->Rnext;
        if (ptr->Rnext != NULL)
        {
            ptr->Rnext->Lnext = prev;
        }
    }

    free(ptr);
    return head;
}

//==============================================================| DELETING A GIVEN KEY IN THE DLL |==========================================================

struct node *del_key_DLL(struct node *head)
{
    printf("DELETING A GIVEN KEY\n");

    int delkey;
    printf("\nEnter the element to be deleted - ");
    scanf("%d", &delkey);

    struct node *ptr, *temp = NULL;
    ptr = head;

    while (ptr != NULL)
    {
        if (ptr->data == delkey)
        {
            if (temp == NULL)
                head = ptr->Rnext;
            else
                temp->Rnext = ptr->Rnext;

            free(ptr);
            break;
        }
        temp = ptr;
        ptr = ptr->Rnext;
    }
    return head;
}

//==============================================================| DELETING ELEMENT AT THE END OF THE DLL |===================================================

struct node *del_end_DLL(struct node *head)
{
    printf("\nDELETING ELEMENT AT THE END\n");

    if (head == NULL)
    {
        return (head);
    }

    struct node *ptr, *prev;
    for (ptr = head; ptr->Rnext != NULL; ptr = ptr->Rnext)
    {
        prev = ptr;
    }
    prev->Rnext = NULL;
    free(ptr);
    printf("The entered element has successfully been deleted.\n");
    return (head);
}