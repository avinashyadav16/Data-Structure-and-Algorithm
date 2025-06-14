/**
 *  @file: 10_Reversing_SLL.cpp
 *  @author: Avinash Yadav
 *  @date: 14-06-2025
 *  @brief: Reverse a given SLL
 */

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

/*
Using three pointers:
    - prevN: previous node (reversed portion).
    - currN: current node being processed.
    - nextN: stores the next node to move forward.
*/
Node *reversedSLL(Node *head)
{
    // prevN will ultimately point to the new head
    // (reversed list's head)
    Node *prevN = nullptr;

    // currN starts at the current node we're processing
    // (initially head)
    Node *currN = head;

    // nextN will temporarily store the next node
    // (so we don't lose it)
    Node *nextN = nullptr;

    // Traverse the entire list
    while (currN != nullptr)
    {
        // Store the next node before changing any pointers
        nextN = currN->next;

        // Reverse the 'next' pointer of the current node
        // to point to the previous node
        currN->next = prevN;

        // Move the prevN pointer one step forward
        // (now at currN)
        prevN = currN;

        // Move the currN pointer one step forward
        // (continue traversal)
        currN = nextN;
    }

    // After the loop,
    // prevN points to the new head of the reversed list
    return prevN;
}

/////////////////////////////////////////////////////////////////////////
// DRIVE CODE:
/////////////////////////////////////////////////////////////////////////

Node *convertArrayToSLL(vector<int> nums)
{
    Node *head = new Node(nums[0]);
    Node *mover = head;

    for (int i = 1; i < nums.size(); i++)
    {
        Node *temp = new Node(nums[i]);

        mover->next = temp;

        mover = temp;
    }

    return head;
}

void printDLL(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";

        temp = temp->next;
    }
}

int main()
{
    cout << "Enter The Array Elements: ";
    string line;
    getline(cin, line);

    stringstream ss(line);

    int input;
    vector<int> nums;

    while (ss >> input)
    {
        nums.push_back(input);
    }

    Node *head = convertArrayToSLL(nums);
    cout << "\nThe Original Singly Linked List is: ";
    printDLL(head);

    cout << "\nThe Reversed Singly Linked List is: ";
    head = reversedSLL(head);
    printDLL(head);

    return 0;
}