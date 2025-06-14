/**
*  @file: 2_Add_Two_Numbers.cpp
*  @author: Avinash Yadav
*  @date: 14-06-2025
*  @link: https://leetcode.com/problems/add-two-numbers/description/
*  @brief: You are given two non-empty linked lists representing two non-negative integers.
            The digits are stored in reverse order, and each of their nodes contains a single digit.
            Add the two numbers and return the sum as a linked list.
            You may assume the two numbers do not contain any leading zero, except the number 0 itself.

            Example 1:
                Input: l1 = [2,4,3], l2 = [5,6,4]
                Output: [7,0,8]
                Explanation: 342 + 465 = 807.

            Example 2:
                Input: l1 = [0], l2 = [0]
                Output: [0]

            Example 3:
                Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
                Output: [8,9,9,9,0,0,0,1]
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // If either list is empty, return the other
        if (!l1)
        {
            return l2;
        }
        if (!l2)
        {
            return l1;
        }

        // Pointer to traverse l1
        ListNode *t1 = l1;

        // Pointer to traverse l2
        ListNode *t2 = l2;

        // Dummy node to simplify result list construction
        ListNode *dummy = new ListNode(-1);

        // Pointer to build the result list
        ListNode *curr = dummy;

        // To store carry from sum of digits
        int carry = 0;

        // Traverse both lists until both are exhausted
        while (t1 != nullptr || t2 != nullptr)
        {
            // Start with carry from previous addition
            int sum = carry;

            if (t1)
            {
                // Add value from l1 if available
                sum += t1->val;
            }
            if (t2)
            {
                // Add value from l2 if available
                sum += t2->val;
            }

            // Create new node with the digit value (sum % 10)
            ListNode *newNode = new ListNode(sum % 10);

            // Update carry for next iteration
            carry = sum / 10;

            // Link new node to result list
            curr->next = newNode;

            // Move to next node
            curr = curr->next;

            // Move to next nodes in l1 and l2 if available
            if (t1)
            {
                t1 = t1->next;
            }
            if (t2)
            {
                t2 = t2->next;
            }
        }

        // If there's a remaining carry, add a new node
        if (carry)
        {
            ListNode *newNode = new ListNode(carry);
            curr->next = newNode;
        }

        // Return the next node of dummy,
        // which is the head of the result list
        return dummy->next;
    }
};