/**
 *  @file: Inserting_Before_Tail_In_DLL.cpp
 *  @author: Avinash Yadav
 *  @date: 13-06-2025
 *  @brief: Inserting a node before Tail of a DLL.
 */

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *back;

    Node() : data(0), next(nullptr), back(nullptr) {}
    Node(int x) : data(x), next(nullptr), back(nullptr) {}
    Node(int x, Node *next, Node *back) : data(x), next(next), back(back) {}
};

Node *insertBeforeTailDLL(Node *head, int val)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    // If there is only one node,
    // insert before it (as new head)
    if (head->next == nullptr)
    {
        Node *newNode = new Node(val, head, nullptr);
        head->back = newNode;

        return newNode;
    }

    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    Node *prev = tail->back;
    Node *newNode = new Node(val, tail, prev);

    prev->next = newNode;
    tail->back = newNode;

    return head;
}

//////////////////////////////////////////////////////////////////////////////
// DRIVER CODE
//////////////////////////////////////////////////////////////////////////////

Node *convertArrayToDLL(vector<int> nums)
{
    Node *head = new Node(nums[0]);
    Node *prev = head;

    for (int i = 1; i < nums.size(); i++)
    {
        Node *temp = new Node(nums[i], nullptr, prev);

        prev->next = temp;

        prev = temp;
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
    cout << "Enter The DLL Elements: ";
    string line;
    getline(cin, line);

    stringstream ss(line);

    int input;
    vector<int> nums;

    while (ss >> input)
    {
        nums.push_back(input);
    }

    Node *head = convertArrayToDLL(nums);

    int val;
    cout << "Enter New Value: ";
    cin >> val;

    cout << "The DLL Before New Node Insertion is: ";
    printDLL(head);

    cout << "\nThe DLL After New Node Insertion is: ";
    head = insertBeforeTailDLL(head, val);
    printDLL(head);

    return 0;
}