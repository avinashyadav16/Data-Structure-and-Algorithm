/**
 *  @file: Linked_List_Cycle_II.cpp
 *  @author: Avinash Yadav
 *  @brief:
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // Edge case:
        // If the linked list is empty or has only one node,
        // there can't be a cycle.
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }

        // Two pointers for Floyd's Cycle Detection Algorithm
        // Moves one step at a time
        ListNode *slowPtr = head;

        // Moves two steps at a time
        ListNode *fastPtr = head;

        // Phase 1: Detect if a cycle exists
        while (fastPtr != NULL && fastPtr->next != NULL)
        {
            // Move slow by 1 step
            slowPtr = slowPtr->next;

            // Move fast by 2 steps
            fastPtr = fastPtr->next->next;

            // If slow and fast meet, there is a cycle
            if (slowPtr == fastPtr)
            {
                break;
            }
        }

        // If the fast pointer reached NULL,
        // there is no cycle in the linked list
        if (fastPtr == NULL || fastPtr->next == NULL)
        {
            return NULL;
        }

        // Phase 2: Find the start of the cycle
        ListNode *cycleStartPtr = head;

        // Move both pointers one step at a time
        // until they meet at the cycle start
        while (cycleStartPtr != slowPtr)
        {
            cycleStartPtr = cycleStartPtr->next;
            slowPtr = slowPtr->next;
        }

        // The node where they meet is the start of the cycle
        return slowPtr;
    }
};
