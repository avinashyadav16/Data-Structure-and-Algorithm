/**
*  @file: Subset_sum_equal_to_target.cpp
*  @author: Avinash Yadav
*  @date: 24-06-2025
*  @link: https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
*  @brief: Given an array of positive integers arr[] and a value sum,
            determine if there is a subset of arr[] with sum equal to given sum.

            Examples:
                Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
                Output: true
                Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

                Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
                Output: false
                Explanation: There is no subset with target sum 30.

                Input: arr[] = [1, 2, 3], sum = 6
                Output: true
                Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
*/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    // Recursive helper function to check if subset sum exists
    bool recursionIsSubsetSum(int idx, vector<int> &arr, int sum)
    {
        // Base case:
        // If sum is 0, empty subset always possible
        if (sum == 0)
        {
            return true;
        }

        // Base case:
        // Only one element left, check if it equals sum
        if (idx == 0)
        {
            return arr[0] == sum;
        }

        // Exclude current element
        bool notTake = recursionIsSubsetSum(idx - 1, arr, sum);

        // Include current element if it does not exceed sum
        bool take = false;
        if (arr[idx] <= sum)
        {
            take = recursionIsSubsetSum(idx - 1, arr, sum - arr[idx]);
        }

        // Return true
        // if either including or excluding gives the sum
        return notTake || take;
    }

    // Public function to start recursion
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        return recursionIsSubsetSum(arr.size() - 1, arr, sum);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    // Recursive helper with memoization (top-down DP)
    bool memoIsSubsetSum(int idx, vector<vector<int>> &dp,
                         vector<int> &arr, int sum)
    {
        // Base case: If sum is 0, subset found
        if (sum == 0)
        {
            return true;
        }

        // Base case: Only one element left
        if (idx == 0)
        {
            return arr[0] == sum;
        }

        // Check if already computed
        if (dp[idx][sum] != -1)
        {
            return dp[idx][sum];
        }

        // Exclude current element
        bool notTake = memoIsSubsetSum(idx - 1, dp, arr, sum);

        // Include current element if possible
        bool take = false;
        if (arr[idx] <= sum)
        {
            take = memoIsSubsetSum(idx - 1, dp, arr, sum - arr[idx]);
        }

        // Store result in dp table
        return dp[idx][sum] = notTake || take;
    }

    // Public function to initialize dp and start recursion
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();

        // dp[i][j] = -1 means not computed, 0/1 means false/true
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return memoIsSubsetSum(n - 1, dp, arr, sum);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// TABULATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution3
{
public:
    // Bottom-up DP approach
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();

        // dp[i][j] = true
        // if subset with sum j is possible using first i elements
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Sum 0 is always possible (empty subset)
        for (int idx = 0; idx < n; idx++)
        {
            dp[idx][0] = true;
        }

        // If first element is <= sum, mark it as possible
        if (arr[0] <= sum)
        {
            dp[0][arr[0]] = true;
        }

        // Fill the dp table
        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 1; target <= sum; target++)
            {
                // Exclude current element
                bool notTake = dp[idx - 1][target];

                // Include current element if possible
                bool take = false;
                if (arr[idx] <= target)
                {
                    take = dp[idx - 1][target - arr[idx]];
                }

                dp[idx][target] = notTake || take;
            }
        }

        // Final answer:
        // is it possible to get 'sum' using all elements?
        return dp[n - 1][sum];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// SPACE OPTIMIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution4
{
public:
    // Optimized bottom-up DP using two 1D arrays
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();

        // prevDP: stores results for previous row, tempDP: current row
        vector<bool> prevDP(sum + 1, false);
        vector<bool> tempDP(sum + 1, false);

        // Sum 0 is always possible
        prevDP[0] = tempDP[0] = true;

        // If first element is <= sum, mark it as possible
        if (arr[0] <= sum)
        {
            prevDP[arr[0]] = true;
        }

        // Fill dp arrays row by row
        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 1; target <= sum; target++)
            {
                // Exclude current element
                bool notTake = prevDP[target];

                // Include current element if possible
                bool take = false;
                if (arr[idx] <= target)
                {
                    take = prevDP[target - arr[idx]];
                }

                tempDP[target] = notTake || take;
            }

            // Move to next row
            prevDP = tempDP;
        }

        // Final answer
        return prevDP[sum];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{

    vector<int> arr1 = {3, 34, 4, 12, 5, 2}; // OUTPUT: true
    int sum1 = 9;

    vector<int> arr2 = {3, 34, 4, 12, 5, 2}; // OUTPUT: false
    int sum2 = 30;

    vector<int> arr3 = {1, 2, 3}; // OUTPUT: true
    int sum3 = 6;

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << boolalpha << sol1.isSubsetSum(arr1, sum1) << endl;
    cout << boolalpha << sol1.isSubsetSum(arr2, sum2) << endl;
    cout << boolalpha << sol1.isSubsetSum(arr3, sum3) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << boolalpha << sol2.isSubsetSum(arr1, sum1) << endl;
    cout << boolalpha << sol2.isSubsetSum(arr2, sum2) << endl;
    cout << boolalpha << sol2.isSubsetSum(arr3, sum3) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << boolalpha << sol3.isSubsetSum(arr1, sum1) << endl;
    cout << boolalpha << sol3.isSubsetSum(arr2, sum2) << endl;
    cout << boolalpha << sol3.isSubsetSum(arr3, sum3) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << boolalpha << sol4.isSubsetSum(arr1, sum1) << endl;
    cout << boolalpha << sol4.isSubsetSum(arr2, sum2) << endl;
    cout << boolalpha << sol4.isSubsetSum(arr3, sum3) << endl;

    return 0;
}