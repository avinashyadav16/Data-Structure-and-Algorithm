/**
*  @file: 04_Inserting_A_Node_In_LL.cpp
*  @author: Avinash Yadav
*  @date: 11-06-2025
*  @brief: Given a postion 'k' insert the node at the defined place.
            Given a linked list and an integer value val, insert a new node with that value
            at the kth place of the list and return the updated linked list.
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

// ---------------------------------------------------------------

Node *insertIntoLL(Node *head, int ele, int k)
{
    if (head == nullptr)
    {
        if (k == 1)
        {
            return new Node(ele);
        }
        else
        {
            return head;
        }
    }

    if (k == 1)
    {
        Node *newNode = new Node(ele, head);

        return newNode;
    }

    int cnt = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        cnt++;

        if (cnt == (k - 1))
        {
            Node *newNode = new Node(ele);
            newNode->next = temp->next;

            temp->next = newNode;

            break;
        }

        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Position is out of bounds to insert in between(head & tail)." << endl;
    }

    return head;
}

// ---------------------------------------------------------------
// DRIVER CODE:

Node *convertArrayToLL(vector<int> nums)
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

void displayLL(Node *head)
{
    cout << "The Linked List Is: ";

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";

        temp = temp->next;
    }
}

int main()
{
    cout << "Enter The LL Values:  ";

    string line;
    getline(cin, line);

    stringstream ss(line);

    int input;
    vector<int> nums;

    while (ss >> input)
    {
        nums.push_back(input);
    }

    Node *head = convertArrayToLL(nums);

    int val;
    cout << "Enter The Value: ";
    cin >> val;

    int k;
    cout << "Enter The Position: ";
    cin >> k;

    head = insertIntoLL(head, val, k);

    displayLL(head);

    return 0;
}