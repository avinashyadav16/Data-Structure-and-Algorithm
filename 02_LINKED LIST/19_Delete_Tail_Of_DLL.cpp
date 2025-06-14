/**
 *  @file: Delete_Tail_Of_DLL.cpp
 *  @author: Avinash Yadav
 *  @date: 13-06-2025
 *  @brief: Delete Tail of a DLL.
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

Node *deleteTailDLL(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *tail = head;

    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    Node *newTail = tail->back;
    newTail->next = nullptr;

    tail->back = nullptr;
    delete tail;

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

    cout << "The DLL Before Tail Deletion is: ";
    printDLL(head);

    cout << "\nThe DLL After Tail Deletion is: ";
    head = deleteTailDLL(head);
    printDLL(head);

    return 0;
}