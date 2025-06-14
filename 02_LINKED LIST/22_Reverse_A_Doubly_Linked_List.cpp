/**
*  @file: Reverse_A_Doubly_Linked_List.cpp
*  @author: Avinash Yadav
*  @date: 14-06-2025
*  @link: https://www.naukri.com/code360/problems/reverse-a-doubly-linked-list_1116098?leftPanelTabValue=PROBLEM
*  @brief: You are given a doubly-linked list of size 'N', consisting of positive integers.
            Now your task is to reverse it and return the head of the modified list.

            Example:
                Input:
                4
                4 3 2 1
                This means you have been given doubly linked list of size 4 = 4 <-> 3 <-> 2 <-> 1.

                Output:
                1 2 3 4
                This means after reversing the doubly linked list it becomes 1 <-> 2 <-> 3 <-> 4.
*/

#include <bits/stdc++.h>
using namespace std;

// Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next, *prev;

    Node()
    {
        this->data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

Node *reverseDLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *curr = head;
    Node *last = nullptr;

    while (curr != nullptr)
    {
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;

        curr = curr->prev;
    }

    return last->prev;
}