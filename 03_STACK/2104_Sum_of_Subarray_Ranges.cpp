/**
*  @file: 2104_Sum_of_Subarray_Ranges.cpp
*  @author: Avinash Yadav
*  @date: 14-08-2025
*  @link: https://leetcode.com/problems/sum-of-subarray-ranges/description/
*  @brief: You are given an integer array nums.
        The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
            Return the sum of all subarray ranges of nums.
            A subarray is a contiguous non-empty sequence of elements within an array.

            Example 1:
                Input: nums = [1,2,3]
                Output: 4
                Explanation: The 6 subarrays of nums are the following:
                [1], range = largest - smallest = 1 - 1 = 0
                [2], range = 2 - 2 = 0
                [3], range = 3 - 3 = 0
                [1,2], range = 2 - 1 = 1
                [2,3], range = 3 - 2 = 1
                [1,2,3], range = 3 - 1 = 2
                So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

            Example 2:
                Input: nums = [1,3,3]
                Output: 4
                Explanation: The 6 subarrays of nums are the following:
                [1], range = largest - smallest = 1 - 1 = 0
                [3], range = 3 - 3 = 0
                [3], range = 3 - 3 = 0
                [1,3], range = 3 - 1 = 2
                [3,3], range = 3 - 3 = 0
                [1,3,3], range = 3 - 1 = 2
                So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.

            Example 3:
                Input: nums = [4,-2,-3,4,1]
                Output: 59
                Explanation: The sum of all subarray ranges of nums is 59.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Find Previous Smaller Element's Index for each element
    // For each i,
    // PSEE[i] is the index of the previous element < arr[i],
    // or -1 if none
    vector<int> findPSEE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> PSEE(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            // Maintain a monotonic increasing stack
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            // If stack is empty, no previous smaller,
            // else top is previous smaller
            PSEE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return PSEE;
    }

    // Find Next Smaller Element's Index for each element
    // For each i,
    // NSE[i] is the index of the next element < arr[i],
    // or n if none
    vector<int> findNSE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> NSE(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            // Maintain a monotonic increasing stack
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return NSE;
    }

    // Find Previous Greater Element's Index for each element
    // For each i,
    // PGEE[i] is the index of the previous element > arr[i],
    // or -1 if none
    vector<int> findPGEE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> PGEE(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            // Maintain a monotonic decreasing stack
            while (!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }
            PGEE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return PGEE;
    }

    // Find Next Greater Element's Index for each element
    // For each i,
    // NGE[i] is the index of the next element > arr[i],
    // or n if none
    vector<int> findNGE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> NGE(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            // Maintain a monotonic decreasing stack
            while (!st.empty() && arr[st.top()] < arr[i])
            {
                st.pop();
            }
            NGE[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return NGE;
    }

    // Calculate the sum of minimums of all subarrays
    // For each arr[i],
    // count how many subarrays where arr[i] is the minimum
    long long sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> NSE = findNSE(arr);
        vector<int> PSEE = findPSEE(arr);
        long long total = 0;

        for (int i = 0; i < n; i++)
        {
            // Number of subarrays where arr[i] is the minimum:
            // (i - PSEE[i]) * (NSE[i] - i)
            int leftMin = i - PSEE[i];
            int rightMin = NSE[i] - i;
            long long contrib = (long long)leftMin * rightMin * (long long)arr[i];
            total += contrib;
        }
        return total;
    }

    // Calculate the sum of maximums of all subarrays
    // For each arr[i],
    // count how many subarrays where arr[i] is the maximum
    long long sumSubarrayMax(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> NGE = findNGE(arr);
        vector<int> PGEE = findPGEE(arr);
        long long total = 0;

        for (int i = 0; i < n; i++)
        {
            // Number of subarrays where arr[i] is the maximum:
            // (i - PGEE[i]) * (NGE[i] - i)
            int leftMax = i - PGEE[i];
            int rightMax = NGE[i] - i;
            long long contrib = (long long)leftMax * rightMax * (long long)arr[i];
            total += contrib;
        }
        return total;
    }

    // Main function:
    // sum of all subarray ranges =
    // sum of all subarray maximums - sum of all subarray minimums
    long long subArrayRanges(vector<int> &nums)
    {
        return sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    cout << sol.subArrayRanges(nums) << endl; // Output: 4

    nums = {1, 3, 3};
    cout << sol.subArrayRanges(nums) << endl; // Output: 4

    nums = {4, -2, -3, 4, 1};
    cout << sol.subArrayRanges(nums) << endl; // Output: 59

    return 0;
}
