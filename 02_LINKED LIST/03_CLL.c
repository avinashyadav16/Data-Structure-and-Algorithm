#include <stdio.h>
#include <stdlib.h>

//===================================================================| FUNCTION DECLARATION |================================================================

struct node *create_CLL(int);                     // FUNCTION DECLERATION -   01
void display_CLL(struct node *head);              // FUNCTION DECLERATION -   02
void search_CLL(struct node *head);               // FUNCTION DECLERATION -   03
struct node *insert_big_CLL(struct node *head);   // FUNCTION DECLERATION -   04
struct node *insert_bfloc_CLL(struct node *head); // FUNCTION DECLERATION -   05
struct node *insert_afloc_CLL(struct node *head); // FUNCTION DECLERATION -   06
struct node *insert_bfkey_CLL(struct node *head); // FUNCTION DECLERATION -   07
struct node *insert_afkey_CLL(struct node *head); // FUNCTION DECLERATION -   08
struct node *insert_end_CLL(struct node *head);   // FUNCTION DECLERATION -   09
struct node *del_big_CLL(struct node *head);      // FUNCTION DECLERATION -   10
struct node *del_bfloc_CLL(struct node *head);    // FUNCTION DECLERATION -   11
struct node *del_afloc_CLL(struct node *head);    // FUNCTION DECLERATION -   12
struct node *del_key_CLL(struct node *head);      // FUNCTION DECLERATION -   13
struct node *del_end_CLL(struct node *head);      // FUNCTION DECLERATION -   14

struct node
{
    int data;
    struct node *next;
};
struct node *head;

//========================================================================| MAIN FUNCTION |==================================================================

int main()
{
    printf("\t\t\t\t1.  CREATE A CLL\n");
    printf("\t\t\t\t2.  DISPLAY CLL\n");
    printf("\t\t\t\t3.  SEARCH IN CLL\n");
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
            printf("\nCREATING CLL:\n");
            printf("Enter the number of nodes in the CLL: ");
            scanf("%d", &size);
            head = create_CLL(size);
            break;

        case 2:
            display_CLL(head);
            break;

        case 3:
            search_CLL(head);
            break;

        case 4:
            head = insert_big_CLL(head);
            display_CLL(head);
            break;

        case 5:
            head = insert_bfloc_CLL(head);
            display_CLL(head);
            break;

        case 6:
            head = insert_afloc_CLL(head);
            display_CLL(head);
            break;

        case 7:
            head = insert_bfkey_CLL(head);
            display_CLL(head);
            break;

        case 8:
            head = insert_afkey_CLL(head);
            display_CLL(head);
            break;

        case 9:
            head = insert_end_CLL(head);
            display_CLL(head);
            break;

        case 10:
            head = del_big_CLL(head);
            display_CLL(head);
            break;

        case 11:
            head = del_bfloc_CLL(head);
            display_CLL(head);
            break;

        case 12:
            head = del_afloc_CLL(head);
            display_CLL(head);
            break;

        case 13:
            head = del_key_CLL(head);
            display_CLL(head);
            break;

        case 14:
            head = del_end_CLL(head);
            display_CLL(head);
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

//==============================================================| CREATING CIRCULARLY LINKED LINK |=====================================================================

struct node *create_CLL(int n)
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
    ptr->next = head;
    printf("\n");
    return head;
}

//==============================================================| DISPLAYING THE CLL ELEMENTS |==============================================================

void display_CLL(struct node *head)
{
    printf("DISPLAYING CLL\n");
    printf("Elements in the CLL are: ");

    struct node *ptr;
    ptr = head;

    printf("%d ", ptr->data);
    ptr = ptr->next;

    while (ptr != head)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

//==============================================================| SEARCHING ELEMENTS IN CLL |================================================================

void search_CLL(struct node *head)
{
    printf("SEARCHING CLL\n");
    struct node *ptr;
    ptr = head;
    int value, flag = 0;
    printf("Enter an Element to search - ");
    scanf("%d", &value);

    if (ptr->data == value)
    {
        printf("Result - %d Found in the CLL.\n\n", value);
    }
    else
    {
        ptr = ptr->next;
        while (ptr != head)
        {
            if (ptr->data == value)
            {
                flag = 1;
            }
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("Result - %d Found in the CLL.\n\n", value);
        }
        else
        {
            printf("Result - %d not found in the CLL.\n\n", value);
        }
    }
}

//==============================================================| INSERTING ELEMENT AT THE BEGININNG |=======================================================

struct node *insert_big_CLL(struct node *head)
{
    printf("INSERTING ELEMENT AT THE BEGININNG\n");
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be inserted at the beginning: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    head = newnode;

    printf("%d has been inserted at the beginning.\n\n", newnode->data);
    return head;
}

//==============================================================| INSERTING ELEMENT BEFORE A LOCATION |=====================================================

struct node *insert_bfloc_CLL(struct node *head)
{
    printf("INSERTING ELEMENT BEFORE A LOCATION\n");
    int loc, count = 1;
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the element to be inserted: ");
    scanf("%d", &newnode->data);
    ptr = head;

    printf("Enter before which location it should be inserted: ");
    scanf("%d", &loc);
    if (loc == 1)
    {
        newnode->next = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        head = newnode;
        return head;
    }
    else
    {
        while (ptr->next != head && count != (loc - 1))
        {
            ptr = ptr->next;
            count += 1;
        }
        if (count != (loc - 1))
        {
            printf("Location not found\n");
            return head;
        }

        newnode->next = ptr->next;
        ptr->next = newnode;
        return head;
    }
}
//==============================================================| INSERTING ELEMENT AFTER A LOCATION |=======================================================

struct node *insert_afloc_CLL(struct node *head)
{
    printf("INSERTING ELEMENT AFTER A LOCATION\n");
    int loc, count = 1;
    struct node *newnode, *ptr;
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the element to be inserted: ");
    scanf("%d", &newnode->data);

    printf("Enter after which location it should be inserted: ");
    scanf("%d", &loc);

    while (ptr->next != head && count != loc)
    {
        ptr = ptr->next;
        count += 1;
    }

    if (loc > count)
    {
        printf("\nInvalid location entered by the user\n\n");
        return head;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
    return head;
}

//==============================================================| INSERTING ELEMENT BEFORE AN KEY|===========================================================

struct node *insert_bfkey_CLL(struct node *head)
{
    int key;
    struct node *newnode, *ptr, *prev;
    newnode = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    prev = head;

    printf("Enter the key before which you want to insert: ");
    scanf("%d", &key);
    printf("Enter the element which you want to insert: ");
    scanf("%d", &newnode->data);

    // When we have to insert the element just before the first node:
    if (ptr->data == key)
    {
        newnode->next = ptr;
        ptr = ptr->next;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        head = newnode;
        return head;
    }

    // If we have to insert key in between the CLL:
    // For that move the pointer to next node and itirate till the key meets or the head comes
    ptr = ptr->next;

    while (ptr != head)
    {
        if (ptr->data == key)
        {
            newnode->next = ptr;
            prev->next = newnode;
            return head;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == head)
    {
        printf("The given key %d is not present in CLL", key);
    }
    return head;
}

//==============================================================| INSERTING ELEMENT AFTER AN KEY|============================================================

struct node *insert_afkey_CLL(struct node *head)
{
    struct node *newnode, *ptr, *prev;
    newnode = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    prev = NULL;

    int key;
    printf("Enter the key after which you want to insert: ");
    scanf("%d", &key);
    printf("Enter the element which you want to insert: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        printf("The list is empty\n");
        return head;
    }

    while (ptr->data != key)
    {
        prev = ptr;
        ptr = ptr->next;
        if (ptr == head)
        {
            printf("The given key %d is not present in CLL\n", key);
            return head;
        }
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
    return head;
}


//==============================================================| INSERTING ELEMENT AT THE END |=============================================================

struct node *insert_end_CLL(struct node *head)
{
    
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    ptr = head;

    int key;
    printf("Enter the element which you want to insert at the end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL; // Set newnode's next pointer to NULL as it will be inserted at the end

    if (head == NULL)
    {
        newnode->next = newnode; // The newnode itself becomes the head as it's the only node in the CLL
        return newnode;
    }

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    ptr->next = newnode;
    newnode->next = head; // Connect the newnode to the head to maintain the circular structure

    return head;
}

//==============================================================| DELETING ELEMENT FROM BEGINNING |==========================================================

struct node *del_big_CLL(struct node *head)
{

    struct node *temp = head;
    struct node *ptr = head;

    if (head == NULL)
    {
        printf("The list is empty.\n");
        return head;
    }

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    head = head->next;
    ptr->next = head;
    free(temp);

    return head;
}

//==============================================================| DELETING ELEMENT BEFORE A LOCATION |======================================================

struct node *del_bfloc_CLL(struct node *head)
{
    struct node *ptr, *temp;
    int loc, i;
    printf("Enter the location before which you want to delete the element: ");
    scanf("%d", &loc);

    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    if (loc <= 0)
    {
        printf("Invalid location.\n");
        return head;
    }

    ptr = head;
    for (i = 1; i < loc - 1 && ptr->next != head; i++)
    {
        ptr = ptr->next;
    }

    if (i != loc - 1 || ptr->next == head)
    {
        printf("Invalid location.\n");
        return head;
    }

    temp = ptr->next;
    ptr->next = temp->next;

    if (temp == head)
    {
        head = ptr->next;
    }

    free(temp);
    printf("Node before location %d deleted successfully.\n", loc);
    return head;
}

//==============================================================| DELETING ELEMENT AFTER A LOCATION |========================================================

struct node *del_afloc_CLL(struct node *head)
{
    struct node *ptr, *temp;
    ptr = head;
    int loc, i;
    printf("Enter the location after which you want to delete element: ");
    scanf("%d", &loc);

    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    for (i = 1; i < loc && ptr->next != head; i++)
    {
        ptr = ptr->next;
    }

    if (i < loc || ptr->next == head)
    {
        printf("Invalid location.\n");
        return head;
    }

    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    printf("Node after location %d deleted successfully.\n", loc);
    return head;
}

//==============================================================| DELETING A GIVEN KEY IN THE CLL |==========================================================

struct node *del_key_CLL(struct node *head)
{
    printf("DELETING A KEY\n");
    int delkey;
    struct node *ptr, *temp = NULL;
    ptr = head;

    printf("Enter the key that has to be deleted - ");
    scanf("%d", &delkey);

    // Deleting the first node
    if (head->data == delkey)
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = head->next;
        head = head->next;
        free(ptr);
        return head;
    }

    // Find the node to be deleted
    while (ptr->next != head)
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

    // Deleting the last node
    if (ptr->data == delkey)
    {
        temp->next = head;
        free(ptr);
    }

    return head;
}

//==============================================================| DELETING ELEMENT AT THE END OF THE CLL |===================================================

struct node *del_end_CLL(struct node *head)
{
    struct node *ptr, *temp;
    ptr = head;

    if (head == NULL)
    {
        printf("The list is empty.\n");
        return head;
    }

    // Check if there is only one node in the list
    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    // Traverse to the second last node
    while (ptr->next != head)
    {
        temp = ptr;
        ptr = ptr->next;
    }

    // Delete the last node
    temp->next = head;
    free(ptr);

    return head;
}