/**
 *  @file: Delete_Node_Of_DLL.cpp
 *  @author: Avinash Yadav
 *  @date: 13-06-2025
 *  @brief: Delete The Given Node of a DLL. Given that the node will not be the head of the DLL.
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

void deleteNode(Node *temp)
{
    Node *prevN = temp->back;
    Node *frontN = temp->next;

    if (frontN == nullptr)
    {
        prevN->next = nullptr;
        temp->back = nullptr;

        delete temp;

        return;
    }

    prevN->next = frontN;
    frontN->back = prevN;

    temp->back = nullptr;
    temp->next = nullptr;

    delete temp;
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

    cout << "The DLL Before Node Deletion is: ";
    printDLL(head);

    cout << "\nThe DLL After Node Deletion is: ";
    deleteNode(head->next);
    printDLL(head);

    return 0;
}