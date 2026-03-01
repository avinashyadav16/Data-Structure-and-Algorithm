/**
 * @file: 152_Maximum_Product_Subarray.cpp
 * @author: Avinash Yadav
 * @date: 29-08-2025
 * @link: https://leetcode.com/problems/maximum-product-subarray/description/
 * @brief: Given an integer array nums, find a subarray that has the largest product, and return the product.
            The test cases are generated so that the answer will fit in a 32-bit integer.

        Example 1:
        Input: nums = [2,3,-2,4]
        Output: 6
        Explanation: [2,3] has the largest product 6.

        Example 2:
        Input: nums = [-2,0,-1]
        Output: 0
        Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();

        // prefix: product from left to right
        int prefix = 1;

        // suffix: product from right to left
        int suffix = 1;

        // maxPrd: stores the maximum product found so far
        int maxPrd = INT_MIN;

        // Traverse the array from both ends simultaneously
        for (int i = 0; i < n; i++)
        {
            // If prefix becomes zero, reset to 1
            // (start new subarray)
            if (prefix == 0)
            {
                prefix = 1;
            }

            // If suffix becomes zero, reset to 1
            // (start new subarray)
            if (suffix == 0)
            {
                suffix = 1;
            }

            // Update prefix product (left to right)
            prefix = prefix * nums[i];
            
            // Update suffix product (right to left)
            suffix = suffix * nums[n - i - 1];

            // Update maxPrd with the maximum of current prefix, suffix, and previous maxPrd
            maxPrd = max(maxPrd, max(prefix, suffix));
        }

        // Return the maximum product found
        return maxPrd;
    }
};