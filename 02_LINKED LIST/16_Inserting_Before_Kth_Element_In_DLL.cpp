/**
 *  @file: Inserting_Before_Kth_Element_In_DLL.cpp
 *  @author: Avinash Yadav
 *  @date: 13-06-2025
 *  @brief: Inserting a node in a DLL before Kth Element.
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

Node *insertBeforeKthDLL(Node *head, int k, int val)
{
    if (head == nullptr || k < 1)
    {
        return head;
    }

    if (k == 1)
    {
        Node *newHead = new Node(val, head, nullptr);
        head->back = newHead;
        return newHead;
    }

    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
        {
            break;
        }
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        // K is more than the length of DLL,
        // do not insert anything
        return head;
    }

    Node *prev = temp->back;
    Node *newNode = new Node(val, temp, prev);

    prev->next = newNode;
    temp->back = newNode;

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

    int k;
    cout << "Enter Kth Position: ";
    cin >> k;

    int val;
    cout << "Enter Value: ";
    cin >> val;

    cout << "The DLL Before New Node Insertion is: ";
    printDLL(head);

    cout << "\nThe DLL After New Node Insertion is: ";
    head = insertBeforeKthDLL(head, k, val);
    printDLL(head);

    return 0;
}