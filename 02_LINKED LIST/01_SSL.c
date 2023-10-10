#include <stdio.h>
#include <stdlib.h>

//===============================================================| FUNCTION DECLARATION |====================================================================

struct node *create_SLL(int);                     // FUNCTION DECLERATION -   01
void *display_SLL(struct node *head);             // FUNCTION DECLERATION -   02
void *search_SLL(struct node *head);              // FUNCTION DECLERATION -   03
struct node *insert_big_SLL(struct node *head);   // FUNCTION DECLERATION -   04
struct node *insert_bfloc_SLL(struct node *head); // FUNCTION DECLERATION -   05
struct node *insert_afloc_SLL(struct node *head); // FUNCTION DECLERATION -   06
struct node *insert_bfkey_SLL(struct node *head); // FUNCTION DECLERATION -   07
struct node *insert_afkey_SLL(struct node *head); // FUNCTION DECLERATION -   08
struct node *insert_end_SLL(struct node *head);   // FUNCTION DECLERATION -   09
struct node *del_big_SLL(struct node *head);      // FUNCTION DECLERATION -   10
struct node *del_bfloc_SLL(struct node *head);    // FUNCTION DECLERATION -   11
struct node *del_afloc_SLL(struct node *head);    // FUNCTION DECLERATION -   12
struct node *del_key_SLL(struct node *head);      // FUNCTION DECLERATION -   13
struct node *del_end_SLL(struct node *head);      // FUNCTION DECLERATION -   14

struct node
{
    int data;
    struct node *next;
};
struct node *head;

//==============================================================| MAIN FUNCTION |============================================================================

int main()
{
    printf("\t\t\t\t1.  CREATE A SLL\n");
    printf("\t\t\t\t2.  DISPLAY SLL\n");
    printf("\t\t\t\t3.  SEARCH IN SLL\n");
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
            printf("\nCREATING SLL:\n");
            printf("Enter the number of nodes in the SLL: ");
            scanf("%d", &size);
            head = create_SLL(size);
            break;

        case 2:
            display_SLL(head);
            break;

        case 3:
            search_SLL(head);
            break;

        case 4:
            head = insert_big_SLL(head);
            display_SLL(head);
            break;

        case 5:
            head = insert_bfloc_SLL(head);
            display_SLL(head);
            break;

        case 6:
            head = insert_afloc_SLL(head);
            display_SLL(head);
            break;

        case 7:
            head = insert_bfkey_SLL(head);
            display_SLL(head);
            break;

        case 8:
            head = insert_afkey_SLL(head);
            display_SLL(head);
            break;

        case 9:
            head = insert_end_SLL(head);
            display_SLL(head);
            break;

        case 10:
            head = del_big_SLL(head);
            display_SLL(head);
            break;

        case 11:
            head = del_bfloc_SLL(head);
            display_SLL(head);
            break;

        case 12:
            head = del_afloc_SLL(head);
            display_SLL(head);
            break;

        case 13:
            head = del_key_SLL(head);
            display_SLL(head);
            break;

        case 14:
            head = del_end_SLL(head);
            display_SLL(head);
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

//==============================================================| CREATING SINGLY LINKED LIST |=====================================================================

struct node *create_SLL(int size)
{
    int i;
    struct node *ptr;
    for (i = 1; i <= size; i++)
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

//==============================================================| DISPLAYING THE SINGLY LINKED LIST ELEMENTS |======================================================

void *display_SLL(struct node *head)
{
    printf("DISPLAYING SLL-\n");
    struct node *ptr;
    printf("Elements in the SLL are: ");
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%d  ", ptr->data);
    }
    printf("\n\n");
}

//==============================================================| SEARCHING ELEMENTS IN SINGLY LINKED LIST |========================================================

void *search_SLL(struct node *head)
{
    printf("SEARCHING SLL\n");
    struct node *ptr;
    int value, flag = 0;
    printf("Enter an Element to search - ");
    scanf("%d", &value);
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if ((ptr->data) == value)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Result - Element %d Found in the SLL.\n\n", value);
    }
    else
    {
        printf("Result - Element %d not found in the SLL.\n\n", value);
    }
}

//==============================================================| INSERTING ELEMENT AT THE BEGININNG OF SLL |=======================================================

struct node *insert_big_SLL(struct node *head)
{
    printf("INSERTING ELEMENT AT THE BEGININNG\n");
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be inserted at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    printf("Element %d has been inserted at the beginning of SLL.\n\n", newnode->data);
    return head;
}

//==============================================================| INSERTING ELEMENT BEFORE A GIVEN LOCATION |=============================================

struct node *insert_bfloc_SLL(struct node *head)
{
    printf("INSERTING ELEMENT BEFORE A GIVEN LOCATION\n");
    int index, count = 1;
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the element to be inserted: ");
    scanf("%d", &newnode->data);
    ptr = head;

    printf("Enter location before which the element should be inserted: ");
    scanf("%d", &index);

    while (ptr != NULL && count < index)
    {
        ptr = ptr->next;
        count += 1;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
    printf("\n");
    return head;
}

//==============================================================| INSERTING ELEMENT AFTER A GIVEN LOCATION |==============================================

struct node *insert_afloc_SLL(struct node *head)
{
    printf("INSERTING ELEMENT AFTER A GIVEN LOCATION\n");
    int index, count = 0;
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the element to be inserted: ");
    scanf("%d", &newnode->data);
    ptr = head;

    printf("Enter location after which the element should be inserted: ");
    scanf("%d", &index);

    while (ptr != NULL && count != index)
    {
        ptr = ptr->next;
        count += 1;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
    printf("\n");
    return head;
}

//==============================================================| INSERTING ELEMENT BEFORE A KEY |================================================

struct node *insert_bfkey_SLL(struct node *head)
{
    printf("INSERTING ELEMENT BEFORE A KEY\n");
    int key;
    struct node *newnode, *ptr, *prev;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be inserted - ");
    scanf("%d", &newnode->data);

    printf("Enter the key before which the element has to be inserted - ");
    scanf("%d", &key);

    ptr = head;
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->data == key)
        {
            newnode->next = prev->next;
            prev->next = newnode;
        }
        prev = ptr;
    }
    printf("\n");
    return head;
}

//==============================================================| INSERTING ELEMENT AFTER A KEY |=================================================

struct node *insert_afkey_SLL(struct node *head)
{
    printf("INSERTING ELEMENT AFTER A KEY\n");
    int key;
    struct node *newnode, *ptr;
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element value to be inserted - ");
    scanf("%d", &newnode->data);

    printf("Enter the key after which the element has to be inserted - ");
    scanf("%d", &key);

    while (ptr != NULL && ptr->data != key)
    {
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
    printf("\n");
    return head;
}

//==============================================================| INSERTING ELEMENT AT THE END OF SLL |=============================================================

struct node *insert_end_SLL(struct node *head)
{
    printf("INSERTING ELEMENT AT THE END OF SLL\n");
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the element to be inserted at the end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    ptr = head;
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    printf("\n");
    return head;
}

//==============================================================| DELETING AN ELEMENT FROM BEGINNING OF SLL |==========================================================

struct node *del_big_SLL(struct node *head)
{
    printf("DELETING AN ELEMENT FROM BEGINNING OF SLL\n");
    if (head == NULL)
    {
        printf("List is empty.");
        return head;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Element deleted successfully from the beginning of SLL.\n");
    printf("\n");
    return head;
}

//==============================================================| DELETING ELEMENT BEFORE A LOCATION |===========================================

struct node *del_bfloc_SLL(struct node *head)
{
    printf("DELETING ELEMENT BEFORE A LOCATION\n");
    int index;
    printf("Enter location before which the element should be deleted: ");
    scanf("%d", &index);

    struct node *temp = head;
    struct node *ptr = NULL;
    struct node *prev;

    int i;
    for (i = 0; temp != NULL && i < index; i++)
    {
        prev = ptr;
        ptr = temp;
        temp = temp->next;
    }
    prev->next = temp;
    free(ptr);
    printf("Element deleted successfully before the given location.\n");
    printf("\n");
    return head;
}

//==============================================================| DELETING ELEMENT AFTER A LOCATION |============================================

struct node *del_afloc_SLL(struct node *head)
{
    printf("DELETING ELEMENT AFTER A LOCATION\n");
    int index;
    printf("Enter location after which the element should be deleted: ");
    scanf("%d", &index);

    struct node *temp = head;
    struct node *ptr = NULL;

    int i;
    for (i = 0; temp != NULL && i <= index; i++)
    {
        ptr = temp;
        temp = temp->next;
    }

    ptr->next = temp->next;
    free(temp);

    printf("Node deleted after the given index successfully.\n");
    printf("\n");
    return head;
}
//==============================================================| DELETING A KEY IN THE MID OF SLL |===============================================

struct node *del_key_SLL(struct node *head)
{
    printf("DELETING A KEY IN THE MID OF SLL\n");
    int delkey;
    struct node *ptr, *temp;
    ptr = head;

    printf("Enter the key that has to be deleted - ");
    scanf("%d", &delkey);

    while (ptr != NULL)
    {
        if (ptr->data == delkey)
        {
            temp->next = ptr->next;
            free(ptr);
            break;
        }
        temp = ptr;
        ptr = ptr->next;
    }
    printf("\n");
    return head;
}

//==============================================================| DELETING ELEMENT AT THE END  OF SLL |==============================================================

struct node *del_end_SLL(struct node *head)
{
    printf("DELETING ELEMENT AT THE END  OF SLL\n");
    struct node *ptr, *temp = head;
    while (temp->next != NULL)
    {
        ptr = temp;
        temp = temp->next;
    }
    free(temp);
    ptr->next = NULL;
    printf("\n");
    return head;
}