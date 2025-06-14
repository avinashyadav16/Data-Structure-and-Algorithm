/**
 *  @file: Array_To_DLL.cpp
 *  @author: Avinash Yadav
 *  @date: 11-06-2025
 *  @brief: Convert the given array into doubly linked list;
            [1, 3, 2, 5, 4] : 1 <-> 3 <-> 2 <-> 5 <-> 4 -> nullptr
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

    cout << "The Doubly Linked List Is: " << endl;
    while (temp != nullptr)
    {
        cout << temp->data << " " << temp->next << " " << temp->back << endl;

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

    Node *head = convertArrayToDLL(nums);

    printDLL(head);

    return 0;
}