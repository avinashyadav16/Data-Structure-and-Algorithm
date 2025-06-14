/**
 *  @file: Delete_Head_Of_DLL.cpp
 *  @author: Avinash Yadav
 *  @date: 13-06-2025
 *  @brief: Delete The Head Node of DLL.
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

Node *deleteHeadDLL(Node *head)
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

    Node *temp = head;

    head = head->next;

    head->back = nullptr;
    temp->next = nullptr;

    delete temp;

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

    cout << "The DLL Before Head Deletion is: ";
    printDLL(head);

    cout << "\nThe DLL After Head Deletion is: ";
    head = deleteHeadDLL(head);
    printDLL(head);

    return 0;
}