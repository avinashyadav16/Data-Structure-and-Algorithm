/**
*  @file: 496_Next_Greater_Element_I.cpp
*  @author: Avinash Yadav
*  @date: 10-08-2025
*  @link: https://leetcode.com/problems/next-greater-element-i/description/
*  @brief: The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
            You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
            For each 0 <= i < nums1.length,
                find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
            If there is no next greater element, then the answer for this query is -1.
            Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

            Example 1:
                Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
                Output: [-1,3,-1]
                Explanation: The next greater element for each value of nums1 is as follows:
                - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
                - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
                - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

            Example 2:
                Input: nums1 = [2,4], nums2 = [1,2,3,4]
                Output: [3,-1]
                Explanation: The next greater element for each value of nums1 is as follows:
                - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
                - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n2 = nums2.size();

        // NGE[i] will store the NGE for nums2[i]
        vector<int> NGE(n2);

        // Stack to keep track of elements
        // for which we haven't found the next greater
        stack<int> st;

        // Traverse nums2 from right to left
        // to find NGEs
        for (int i = n2 - 1; i >= 0; i--)
        {
            // Pop elements from the stack
            // that are less than or equal to nums2[i]
            // because they can't be the next greater for nums2[i]
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }

            // If stack is empty,
            // there is no greater element to the right
            if (st.empty())
            {
                NGE[i] = -1;
            }
            else
            {
                // The top of the stack is the NGE
                NGE[i] = st.top();
            }

            // Push current element to stack for next iteration
            st.push(nums2[i]);
        }

        int n1 = nums1.size();
        vector<int> result(n1);

        // Map to store the index of each element
        // in nums2 for quick lookup
        unordered_map<int, int> idx_map;
        for (int i = 0; i < n2; ++i)
        {
            idx_map[nums2[i]] = i;
        }

        // For each element in nums1,
        // find its index in nums2 and get its NGE
        for (int i = 0; i < n1; i++)
        {
            int idx_in_nums2 = idx_map[nums1[i]];
            result[i] = NGE[idx_in_nums2];
        }

        return result;
    }
};

