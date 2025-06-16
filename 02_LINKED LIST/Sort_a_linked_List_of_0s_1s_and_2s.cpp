/**
*  @file: Sort_a_linked_ist_of_0s_1s_and_2s.cpp
*  @author: Avinash Yadav
*  @date: 16-06-2025
*  @link: https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
*  @brief: Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only.
            Your task is to rearrange the list so that
            all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

            Examples:
                Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
                Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2
                Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.

                Input: head = 2 → 2 → 0 → 1
                Output: 0 → 1 → 2 → 2
                Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be 0 → 1 → 2 → 2.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

//////////////////////////////////////////////////////////////////////////////////
// BRUTE FORCE APPROACH:
//////////////////////////////////////////////////////////////////////////////////

class Solution1
{
public:
    Node *segregate(Node *head)
    {
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == 0)
            {
                cnt0++;
            }
            else if (temp->data == 1)
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }

            temp = temp->next;
        }

        temp = head;
        while (temp != nullptr)
        {
            if (cnt0)
            {
                temp->data = 0;
                cnt0--;
            }
            else if (cnt1)
            {
                temp->data = 1;
                cnt1--;
            }
            else
            {
                temp->data = 2;
                cnt2--;
            }

            temp = temp->next;
        }

        return head;
    }
};

//////////////////////////////////////////////////////////////////////////////////
// OPTIMIZED APPROACH:
//////////////////////////////////////////////////////////////////////////////////

// This approach uses three dummy nodes to create three separate linked lists
// for 0s, 1s, and 2s. It then connects these lists together to form the sorted list.
// This avoids changing node data and only manipulates pointers, making it more optimal.

class Solution2
{
public:
    Node *segregate(Node *head)
    {
        // Edge case: If the list is empty or has only one node, it's already sorted.
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        // Create dummy heads for three lists: 0s, 1s, and 2s.
        Node *zeroHead = new Node(-1); // Dummy head for 0s list
        Node *zero = zeroHead;         // Tail pointer for 0s list

        Node *oneHead = new Node(-1); // Dummy head for 1s list
        Node *one = oneHead;          // Tail pointer for 1s list

        Node *twoHead = new Node(-1); // Dummy head for 2s list
        Node *two = twoHead;          // Tail pointer for 2s list

        Node *temp = head; // Pointer to traverse the original list

        // Traverse the original list and distribute nodes into the three lists
        while (temp != nullptr)
        {
            if (temp->data == 0)
            {
                zero->next = temp; // Append to 0s list
                zero = temp;       // Move tail
            }
            else if (temp->data == 1)
            {
                one->next = temp; // Append to 1s list
                one = temp;       // Move tail
            }
            else // temp->data == 2
            {
                two->next = temp; // Append to 2s list
                two = temp;       // Move tail
            }

            temp = temp->next; // Move to next node
        }

        // Connect the three lists together:
        // 0s list -> 1s list -> 2s list
        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = nullptr; // End the list

        // The new head is the next of zeroHead dummy node
        Node *newHead = zeroHead->next;

        // Free the dummy nodes to avoid memory leaks
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
    }
};