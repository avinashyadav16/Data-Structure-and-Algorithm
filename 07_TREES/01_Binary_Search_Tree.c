#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left_child;
    int data;
    struct node *right_child;
};

struct node *create_node(int);
void insert_BST(struct node **root, int item);

void preorder_display(struct node *);
void inorder_display(struct node *);
void postorder_display(struct node *);

int main()
{
    struct node *root = NULL;

    insert_BST(&root, 45);
    insert_BST(&root, 36);
    insert_BST(&root, 76);
    insert_BST(&root, 23);
    insert_BST(&root, 89);
    insert_BST(&root, 115);
    insert_BST(&root, 98);
    insert_BST(&root, 39);
    insert_BST(&root, 41);
    insert_BST(&root, 56);
    insert_BST(&root, 69);
    insert_BST(&root, 48);

    printf("PRE-OREDR TRAVERSAL IS:  ");
    preorder_display(root);
    printf("\n");

    printf("IN-OREDR TRAVERSAL IS:   ");
    inorder_display(root);
    printf("\n");

    printf("POST-OREDR TRAVERSAL IS: ");
    postorder_display(root);
    return 0;
}

struct node *create_node(int item)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->left_child = NULL;
    newnode->right_child = NULL;
    return newnode;
}

void insert_BST(struct node **root, int item)
{
    struct node *current;
    struct node *parent;

    if (*root == NULL)
    {
        *root = create_node(item);
    }
    else
    {
        current = *root;
        parent = NULL;
        while (1)
        {
            parent = current;
            if (item < current->data)
            {
                current = current->left_child;
                if (current == NULL)
                {
                    parent->left_child = create_node(item);
                    return;
                }
            }
            else
            {
                current = current->right_child;
                if (current == NULL)
                {
                    parent->right_child = create_node(item);
                    return;
                }
            }
        }
    }
}

void preorder_display(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder_display(root->left_child);
        preorder_display(root->right_child);
    }
}

void inorder_display(struct node *root)
{
    if (root != NULL)
    {
        inorder_display(root->left_child);
        printf("%d ", root->data);
        inorder_display(root->right_child);
    }
}

void postorder_display(struct node *root)
{

    if (root != NULL)
    {
        postorder_display(root->left_child);
        postorder_display(root->right_child);
        printf("%d ", root->data);
    }
}
