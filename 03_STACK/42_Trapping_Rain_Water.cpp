/**
*  @file: 42_Trapping_Rain_Water.cpp
*  @author: Avinash Yadav
*  @date: 12-08-2025
*  @link: https://leetcode.com/problems/trapping-rain-water/description/
*  @brief: Given n non-negative integers representing an elevation map where the width of each bar is 1,
            compute how much water it can trap after raining.
            Example 1:
                Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
                Output: 6
                Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

            Example 2:
                Input: height = [4,2,0,3,2,5]
                Output: 9

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to compute the total trapped rain water
    int trap(vector<int> &height)
    {
        int n = height.size();

        // prefix[i] stores the
        // maximum height to the left of index i (including i)
        vector<int> prefix(n);
        prefix[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = max(prefix[i - 1], height[i]);
        }

        // suffix[i] stores the
        // maximum height to the right of index i (including i)
        vector<int> suffix(n);
        suffix[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = max(suffix[i + 1], height[i]);
        }

        int total = 0;
        // For each position,
        // calculate the water trapped above it
        for (int i = 0; i < n; i++)
        {
            // Maximum height to the left
            int leftMax = prefix[i];

            // Maximum height to the right
            int rightMax = suffix[i];

            // Water trapped at index i is
            // min(leftMax, rightMax) - height[i]
            total += min(leftMax, rightMax) - height[i];
        }

        return total;
    }
};

int main()
{

    return 0;
}