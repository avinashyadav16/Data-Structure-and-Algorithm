/**
*  @file: 907_Sum_of_Subarray_Minimums.cpp
*  @author: Avinash Yadav
*  @date: 13-08-2025
*  @link: https://leetcode.com/problems/sum-of-subarray-minimums/description/
*  @brief: Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
            Since the answer may be large, return the answer modulo 10^9 + 7.
            Example 1:
                Input: arr = [3,1,2,4]
                Output: 17
                Explanation:
                Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
                Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
                Sum is 17.

            Example 2:
                Input: arr = [11,81,94,43,3]
                Output: 444

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Find Previous Smaller Element's Index for each element
    // For each arr[i],
    // find the index of previous element < arr[i]
    vector<int> findPSEE(vector<int> &arr)
    {
        int n = arr.size();

        // Initialize with -1 (no previous smaller)
        vector<int> PSEE(n, -1);

        // Stack stores indices
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            // Pop until we find a smaller element
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            // If stack is not empty,
            // top is previous smaller
            PSEE[i] = st.empty() ? -1 : st.top();

            // Push current index
            st.push(i);
        }

        return PSEE;
    }

    // Find Next Smaller Element's Index for each element
    // For each arr[i],
    // find the index of next element < arr[i]
    vector<int> findNSE(vector<int> &arr)
    {
        int n = arr.size();

        // Initialize with n (no next smaller)
        vector<int> NSE(n, n);

        // Stack stores indices
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            // Pop until we find a smaller element
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            // If stack is not empty, top is next smaller
            NSE[i] = st.empty() ? n : st.top();

            // Push current index
            st.push(i);
        }

        return NSE;
    }

    // Main function to calculate sum of subarray minimums
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();

        int MOD = (int)1e9 + 7;

        // Next Smaller Element indices
        vector<int> NSE = findNSE(arr);

        // Previous Smaller Element indices
        vector<int> PSEE = findPSEE(arr);

        // Use long long to avoid overflow
        long long total = 0;

        for (int i = 0; i < n; i++)
        {
            // Number of subarrays where arr[i] is the minimum:

            // leftMin: number of choices for left boundary
            int leftMin = i - PSEE[i];

            // rightMin: number of choices for right boundary
            int rightMin = NSE[i] - i;

            // Contribution of arr[i] in all such subarrays
            long long contrib = (long long)leftMin * rightMin % MOD * arr[i] % MOD;
            total = (total + contrib) % MOD;
        }

        return (int)total;
    }
};

int main()
{
    Solution sol;

    vector<int> arr1 = {3, 1, 2, 4};        // OUTPUT: 17
    vector<int> arr2 = {11, 81, 94, 43, 3}; // OUTPUT: 444

    cout << sol.sumSubarrayMins(arr1) << endl;
    cout << sol.sumSubarrayMins(arr2) << endl;

    return 0;
}
