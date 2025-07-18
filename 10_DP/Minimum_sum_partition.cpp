/**
*  @file: Minimum_sum_partition.cpp
*  @author: Avinash Yadav
*  @date: 26-06-2025
*  @link: https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
*  @brief: Given an array arr[]  containing non-negative integers,
            the task is to divide it into two sets set1 and set2 such that the absolute difference between their sums is minimum and
            find the minimum difference.

            Examples:
                Input: arr[] = [1, 6, 11, 5]
                Output: 1
                Explanation:
                Subset1 = {1, 5, 6}, sum of Subset1 = 12
                Subset2 = {11}, sum of Subset2 = 11
                Hence, minimum difference is 1.

                Input: arr[] = [1, 4]
                Output: 3
                Explanation:
                Subset1 = {1}, sum of Subset1 = 1
                Subset2 = {4}, sum of Subset2 = 4
                Hence, minimum difference is 3.

                Input: arr[] = [1]
                Output: 1
                Explanation:
                Subset1 = {1}, sum of Subset1 = 1
                Subset2 = {}, sum of Subset2 = 0
                Hence, minimum difference is 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int minDifference(vector<int> &arr)
    {
        int n = arr.size();

        // Calculate the total sum of all elements
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        // dp[i][j] will be true
        // if a subset with sum j can be formed from the first i+1 elements
        vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

        // Base case:
        // sum 0 is always possible (by taking no elements)
        for (int idx = 0; idx < n; idx++)
        {
            dp[idx][0] = true;
        }

        // Base case:
        // first element can form a subset with its own value
        if (arr[0] >= 0 && arr[0] <= totalSum)
        {
            dp[0][arr[0]] = true;
        }

        // Fill the dp table
        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 1; target <= totalSum; target++)
            {
                // Not including current element
                bool notTake = dp[idx - 1][target];

                // Including current element if it does not exceed target
                bool take = false;
                if (arr[idx] >= 0 && arr[idx] <= target)
                {
                    take = dp[idx - 1][target - arr[idx]];
                }

                // Either take or not take the current element
                dp[idx][target] = notTake || take;
            }
        }

        int minDiff = INT_MAX;

        // Find the largest j (sum1)
        // such that dp[n-1][j] is true and j <= totalSum/2
        // This minimizes the difference between
        // sum1 and sum2 = totalSum - sum1
        for (int i = 0; i <= totalSum / 2; i++)
        {
            if (dp[n - 1][i] == true)
            {
                int sum1 = i;
                int sum2 = totalSum - i;

                minDiff = min(minDiff, abs(sum2 - sum1));
            }
        }

        return minDiff;
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    vector<int> nums1 = {3, 9, 7, 3}; // OUTPUT: 2

    vector<int> nums2 = {2, -1, 0, 4, -2, -9}; // OUTPUT: 0

    Solution1 sol1;
    cout << sol1.minDifference(nums1) << endl;
    cout << sol1.minDifference(nums2) << endl;

    return 0;
}