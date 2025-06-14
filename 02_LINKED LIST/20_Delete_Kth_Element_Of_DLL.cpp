/**
 *  @file: Delete_Kth_Element_Of_DLL.cpp
 *  @author: Avinash Yadav
 *  @date: 13-06-2025
 *  @brief: Delete Kth Element of A DLL.
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

Node *deleteKthEle(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;
    int cnt = 0;

    while (temp != nullptr)
    {
        cnt++;

        if (cnt == k)
        {
            break;
        }

        temp = temp->next;
    }

    // If k is out of bounds
    if (temp == nullptr)
    {
        // No kth node exists
        return head;
    }

    Node *prevN = temp->back;
    Node *frontN = temp->next;

    if (prevN == nullptr && frontN == nullptr)
    {
        delete temp;

        return nullptr;
    }
    else if (prevN == nullptr)
    {
        Node *oldHead = head;

        head = head->next;

        head->back = nullptr;
        oldHead->next = nullptr;

        delete oldHead;

        return head;
    }
    else if (frontN == nullptr)
    {
        // Deleting the last node (temp)
        prevN->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return head;
    }

    prevN->next = frontN;
    frontN->back = prevN;

    temp->back = nullptr;
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

    int k;
    cout << "Enter Kth Element: ";
    cin >> k;

    cout << "The DLL Before Kth Element Deletion is: ";
    printDLL(head);

    cout << "\nThe DLL After Kth Element Deletion is: ";
    head = deleteKthEle(head, k);
    printDLL(head);

    return 0;
}