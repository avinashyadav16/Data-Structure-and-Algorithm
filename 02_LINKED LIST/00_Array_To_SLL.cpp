/**
 *  @file: Array_To_LL.cpp
 *  @author: Avinash Yadav
 *  @date: 11-06-2025
 *  @brief: Convert the given array into Singly linked list;
            [1, 3, 2, 5, 4] : 1 -> 3 -> 2 -> 5 -> 4 -> nullptr
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

    Node *temp = head;

    cout << "The Singly Linked List Is: " << endl;
    while (temp != nullptr)
    {
        cout << temp->data << " " << temp->next << endl;

        temp = temp->next;
    }

    return 0;
}