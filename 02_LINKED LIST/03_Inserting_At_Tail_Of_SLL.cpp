#include <bits/stdc++.h>
using namespace std;

// Node class for a linked list
class Node
{
public:
    // Data of the node
    int data;

    // Pointer to the next node in the list
    Node *next;

    // Constructor for a node with only data provided, next initialized to nullptr
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

    // Constructor for a node with both data and next node provided
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

// Function to print the linked list starting from the given head
void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// Function to insert a new node at the tail of the linked list
Node *insertTail(Node *head, int val)
{
    if (head == nullptr)
    {
        return new Node(val);
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = new Node(val);

    return head;
}

int main()
{
    // Initialize a vector with values for the linked list
    vector<int> arr = {12, 5, 8, 7};

    // Create a linked list with the values from the vector
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    cout << "Linked List Before Insertion: ";
    printLL(head);
    cout << endl;

    head = insertTail(head, 500);

    cout << "Linked List After Insertion: ";
    printLL(head);
}