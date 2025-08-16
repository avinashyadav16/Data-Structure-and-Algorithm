/**
*  @file: 85_Maximal_Rectangle.cpp
*  @author: Avinash Yadav
*  @date: 15-08-2025
*  @link: https://leetcode.com/problems/maximal-rectangle/description/
*  @brief: Given a rows x cols binary matrix filled with 0's and 1's,
            find the largest rectangle containing only 1's and return its area.

            Example 1:
                Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
                Output: 6
                Explanation: The maximal rectangle is shown in the above picture.

            Example 2:
                Input: matrix = [["0"]]
                Output: 0

            Example 3:
                Input: matrix = [["1"]]
                Output: 1

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the largest rectangle area in a histogram
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        // Stack to store indices of histogram bars
        stack<int> st;

        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            // Maintain a non-decreasing stack
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                // Index of the popped bar
                int elementIdx = st.top();
                st.pop();

                // Next Smaller Element index
                int NSE = i;

                // Previous Smaller Element index
                int PSE = st.empty() ? -1 : st.top();

                // Calculate area with heights[elementIdx] as the smallest bar
                maxArea = max(maxArea,
                              heights[elementIdx] * (NSE - PSE - 1));
            }
            st.push(i);
        }

        // Process remaining bars in stack
        while (!st.empty())
        {
            int elementIdx = st.top();
            st.pop();
            int NSE = n; // No next smaller, so use n
            int PSE = st.empty() ? -1 : st.top();

            maxArea = max(maxArea,
                          heights[elementIdx] * (NSE - PSE - 1));
        }
        return maxArea;
    }

    // Main function to find maximal rectangle in a binary matrix
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea = 0;

        // prefixSum[i][j] stores
        // the number of consecutive '1's above (including) cell (i, j)
        vector<vector<int>> prefixSum(n, vector<int>(m));

        // Build the prefix sum histogram for each column
        for (int j = 0; j < m; j++)
        {
            int currSum = 0;
            for (int i = 0; i < n; i++)
            {
                // Convert char to int and add to current sum
                currSum += (matrix[i][j] - '0');

                // Reset sum if current cell is '0'
                if (matrix[i][j] == '0')
                {
                    currSum = 0;
                }

                prefixSum[i][j] = currSum;
            }
        }

        // For each row,
        // treat it as a histogram and find the largest rectangle
        for (int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, largestRectangleArea(prefixSum[i]));
        }

        return maxArea;
    }
};

int main()
{

    return 0;
}