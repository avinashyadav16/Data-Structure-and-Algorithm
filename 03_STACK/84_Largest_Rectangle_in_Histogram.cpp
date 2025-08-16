/**
*  @file: 84_Largest_Rectangle_in_Histogram.cpp
*  @author: Avinash Yadav
*  @date: 14-08-2025
*  @link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*  @brief: Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
            return the area of the largest rectangle in the histogram.
            Example 1:
                Input: heights = [2,1,5,6,2,3]
                Output: 10
                Explanation: The above is a histogram where width of each bar is 1.
                The largest rectangle is shown in the red area, which has an area = 10 units.

            Example 2:
                Input: heights = [2,4]
                Output: 4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    // Previous Smaller Element (PSE) for each bar in the histogram
    // For each index i,
    // PSE[i] is the index of the previous bar with height less than heights[i]
    // If there is no such bar, PSE[i] = -1
    vector<int> findPSE(vector<int> &heights)
    {
        int n = heights.size();

        // Initialize PSE with -1
        vector<int> PSE(n, -1);

        // Stack to keep indices of bars
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            // Pop bars from stack until we find a bar shorter than current
            while (!st.empty() &&
                   heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            // If stack is empty, no previous smaller,
            // else top of stack is previous smaller
            PSE[i] = st.empty() ? -1 : st.top();

            // Push current index to stack
            st.push(i);
        }

        return PSE;
    }

    // Next Smaller Element (NSE) for each bar in the histogram
    // For each index i,
    // NSE[i] is the index of the next bar with height less than heights[i]
    // If there is no such bar, NSE[i] = n (out of bounds)
    vector<int> findNSE(vector<int> &heights)
    {
        int n = heights.size();

        // Initialize NSE with n (out of bounds)
        vector<int> NSE(n, n);

        // Stack to keep indices of bars
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            // Pop bars from stack until we find a bar shorter than current
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            // If stack is empty, no next smaller,
            // else top of stack is next smaller
            NSE[i] = st.empty() ? n : st.top();

            // Push current index to stack
            st.push(i);
        }

        return NSE;
    }

    // Main function to calculate largest rectangle area in histogram
    int largestRectangleArea(vector<int> &heights)
    {
        // Previous Smaller Element indices
        vector<int> PSE = findPSE(heights);

        // Next Smaller Element indices
        vector<int> NSE = findNSE(heights);

        int n = heights.size();

        // Store maximum area found
        int maxi = 0;

        for (int i = 0; i < n; i++)
        {
            // Width of rectangle = NSE[i] - PSE[i] - 1
            // Area = heights[i] * width
            int width = NSE[i] - PSE[i] - 1;

            int area = heights[i] * width;

            // Update maximum area
            maxi = max(maxi, area);
        }

        return maxi;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////
// METHOD - 02
//////////////////////////////////////////////////////////////////////////////////////////////////

class Solution2
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        // Stack to store indices of histogram bars
        stack<int> st;

        // Initialize maxArea to 0
        int maxArea = 0;

        // Iterate through all bars of the histogram
        for (int i = 0; i < n; i++)
        {
            // While the current bar is lower than the bar at stack's top,
            // calculate area for the bar at stack's top as the smallest bar
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                // Index of the bar to calculate area for
                int elementIdx = st.top();

                st.pop();

                // Next Smaller Element index (current index)
                int NSE = i;

                // Previous Smaller Element index (top of stack after pop,
                // or -1 if stack is empty)
                int PSE = st.empty() ? -1 : st.top();

                // Calculate area with heights[elementIdx] as the smallest bar
                maxArea = max(maxArea,
                              heights[elementIdx] * (NSE - PSE - 1));
            }

            // Push current bar's index to stack
            st.push(i);
        }

        // Process remaining bars in stack
        while (!st.empty())
        {
            int elementIdx = st.top();
            st.pop();

            // No next smaller element, so use n (end of histogram)
            int NSE = n;

            int PSE = st.empty() ? -1 : st.top();

            maxArea = max(maxArea,
                          heights[elementIdx] * (NSE - PSE - 1));
        }

        return maxArea;
    }
};