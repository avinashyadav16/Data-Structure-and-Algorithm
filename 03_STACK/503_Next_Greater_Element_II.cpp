/**
*  @file: 503_Next_Greater_Element_II.cpp
*  @author: Avinash Yadav
*  @date: 11-08-2025
*  @link: https://leetcode.com/problems/next-greater-element-ii/description/
*  @brief: Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]),
            return the next greater number for every element in nums.

            The next greater number of a number x is the first greater number to its traversing-order next in the array,
            which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

            Example 1:
                Input: nums = [1,2,1]
                Output: [2,-1,2]
                Explanation: The first 1's next greater number is 2;
                The number 2 can't find next greater number.
                The second 1's next greater number needs to search circularly, which is also 2.

            Example 2:
                Input: nums = [1,2,3,4,3]
                Output: [2,3,4,-1,4]

*/

#include <bits/stdc++.h>
using namespace std;

class BruteForceSolution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();

        // Initialize result with -1 for all elements
        vector<int> NGE(n, -1);

        // For each element, check the next n-1 elements circularly
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < (n + i); j++)
            {
                // Wrap around using modulo for circular array
                int index = j % n;

                if (nums[index] > nums[i])
                {
                    // Found the next greater element
                    NGE[i] = nums[index];

                    // Stop searching for this element
                    break;
                }
            }
        }

        return NGE;
    }
};

// Optimized solution:
// Use a stack to keep track of next greater elements efficiently.
// Traverse the array twice (simulate circular array) from right to left.
class OptimizedSolution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        // Result vector
        vector<int> NGE(n);

        // Stack to keep next greater elements
        stack<int> st;

        // Traverse the array twice in reverse
        // to simulate circular behavior
        for (int i = (2 * n - 1); i >= 0; i--)
        {
            // Pop elements from stack
            // that are less than or equal to current element
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }

            // Only fill the result for the first pass (i < n)
            if (i < n)
            {
                // If stack is empty,
                // no greater element exists
                NGE[i] = st.empty() ? -1 : st.top();
            }

            // Push current element onto stack
            st.push(nums[i % n]);
        }

        return NGE;
    }
};

int main()
{

    return 0;
}