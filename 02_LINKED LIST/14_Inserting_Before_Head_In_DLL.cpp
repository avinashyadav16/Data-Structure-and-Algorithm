/**
 *  @file: Inserting_Before_Head_In_DLL.cpp
 *  @author: Avinash Yadav
 *  @date: 13-06-2025
 *  @brief: Inserting a node before head of a DLL and making it a new head;
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

Node *insertBeforeHeadDLL(Node *head, int val)
{
    if (head == nullptr)
    {
        Node *newHead = new Node(val);
        return newHead;
    }

    Node *newHead = new Node(val, head, nullptr);

    head->back = newHead;

    return newHead;
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
    cout << "Enter New Head Value: ";
    cin >> val;

    cout << "The DLL Before Head Insertion is: ";
    printDLL(head);

    cout << "\nThe DLL After Head Insertion is: ";
    head = insertBeforeHeadDLL(head, val);
    printDLL(head);

    return 0;
}