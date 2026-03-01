/**
 *  @file: Linked_List_Cycle.cpp
 *  @brief: This file contains the implementation of the solution to detect a cycle in a singly-linked list.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    /**
     * @brief Determines if a cycle exists in the linked list.
     *
     * @param head The head of the linked list.
     * @return true if a cycle exists, otherwise false.
     */
    bool hasCycle(ListNode *head)
    {
        if (!head)
        {
            // If the list is empty, there is no cycle.
            return false;
        }

        // Slow pointer starts at the head.
        ListNode *slow = head;

        // Fast pointer starts at the second node.
        ListNode *fast = head->next;

        // Traverse the list with two pointers.
        while (slow != fast)
        {
            if (fast == NULL || fast->next == NULL)
            {
                // If fast pointer reaches the end, there is no cycle.
                return false;
            }

            // Move slow pointer one step.
            slow = slow->next;

            // Move fast pointer two steps.
            fast = fast->next->next;
        }

        // If slow and fast pointers meet, there is a cycle.
        return true;
    }
};

class Solution2
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};

class Solution3
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return false;
        }

        map<ListNode *, bool> visited;

        ListNode *temp = head;

        while (temp != NULL)
        {
            if (visited[temp] == true)
            {
                return true;
            }

            visited[temp] = true;
            temp = temp->next;
        }

        return false;
    }
};

int main()
{
    Solution sol;

    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    bool result = sol.hasCycle(head);

    cout << (result ? "Cycle detected in the linked list." : "No cycle detected in the linked list.") << endl;

    return 0;
}