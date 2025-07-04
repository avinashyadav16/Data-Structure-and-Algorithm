/**
*  @file: 328_Odd_Lven_Linked_List.cpp
*  @author: Avinash Yadav
*  @date: 15-06-2025
*  @link: https://leetcode.com/problems/odd-even-linked-list/description/
*  @brief: Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices,
            and return the reordered list.
            The first node is considered odd, and the second node is even, and so on.
            Note that the relative order inside both the even and odd groups should remain as it was in the input.
            You must solve the problem in O(1) extra space complexity and O(n) time complexity.

            Example 1:
                Input: head = [1,2,3,4,5]
                Output: [1,3,5,2,4]

            Example 2:
                Input: head = [2,1,3,5,6,4,7]
                Output: [2,3,6,7,1,5,4]
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

//////////////////////////////////////////////////////////////////////////////////
// BRUTE FORCE APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        vector<int> nums;

        ListNode *odd = head;
        while (odd != nullptr && odd->next != nullptr)
        {
            nums.push_back(odd->val);
            odd = odd->next->next;
        }
        if (odd != nullptr)
        {
            nums.push_back(odd->val);
        }

        ListNode *even = head->next;
        while (even != nullptr && even->next != nullptr)
        {
            nums.push_back(even->val);
            even = even->next->next;
        }
        if (even != nullptr)
        {
            nums.push_back(even->val);
        }

        int i = 0;
        ListNode *temp = head;

        while (temp != nullptr)
        {
            temp->val = nums[i];

            i++;
            temp = temp->next;
        }

        return head;
    }
};

//////////////////////////////////////////////////////////////////////////////////
// OPTIMIZED APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = head->next;

        while (even != nullptr && even->next != nullptr)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};