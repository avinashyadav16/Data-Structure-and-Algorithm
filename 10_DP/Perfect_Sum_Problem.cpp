/**
*  @file: Perfect_Sum_Problem.cpp
*  @author: Avinash Yadav
*  @date: 26-06-2025
*  @link: https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
*  @brief: Given an array arr of non-negative integers and an integer target,
            the task is to count all subsets of the array whose sum is equal to the given target.

            Examples:
                Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
                Output: 3
                Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.

                Input: arr[] = [2, 5, 1, 4, 3], target = 10
                Output: 3
                Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.

                Input: arr[] = [5, 7, 8], target = 3
                Output: 0
                Explanation: There are no subsets of the array that sum up to the target 3.

                Input: arr[] = [35, 2, 8, 22], target = 0
                Output: 1
                Explanation: The empty subset is the only subset with a sum of 0.
*/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    // idx: current index in arr
    // arr: input array
    // target: remaining sum to achieve
    int recursionCntWays(int idx, vector<int> &arr, int target)
    {
        // Base case:
        // when considering the first element (idx == 0)
        if (idx == 0)
        {
            // Special case: if both target and arr[0] are zero,
            // there are two ways: pick or not pick the zero
            if (target == 0 && arr[0] == 0)
            {
                return 2;
            }

            // If target is zero (empty subset) or arr[0] equals target,
            // there is one valid subset
            if (target == 0 || arr[0] == target)
            {
                return 1;
            }

            // Otherwise, no valid subset
            return 0;
        }

        // Option 1:
        // Do not pick the current element
        int notPick = recursionCntWays(idx - 1, arr, target);

        // Option 2:
        // Pick the current element if it does not exceed the target
        int pick = 0;
        if (arr[idx] <= target)
        {
            pick = recursionCntWays(idx - 1, arr, target - arr[idx]);
        }

        // Total ways is sum of both options
        return pick + notPick;
    }

    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();

        return recursionCntWays(n - 1, arr, target);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    // idx: current index in arr
    // arr: input array
    // dp: memoization table (stores results for subproblems)
    // target: remaining sum to achieve
    int memoCntWays(int idx, vector<int> &arr, vector<vector<int>> &dp, int target)
    {
        // Base case: when considering the first element (idx == 0)
        if (idx == 0)
        {
            // Special case: if both target and arr[0] are zero,
            // there are two ways: pick or not pick the zero
            if (target == 0 && arr[0] == 0)
            {
                return 2;
            }

            // If target is zero (empty subset) or arr[0] equals target,
            // there is one valid subset
            if (target == 0 || arr[0] == target)
            {
                return 1;
            }

            // Otherwise, no valid subset
            return 0;
        }

        // If already computed, return the stored result
        if (dp[idx][target] != -1)
        {
            return dp[idx][target];
        }

        // Option 1: Do not pick the current element
        int notPick = memoCntWays(idx - 1, arr, dp, target);

        // Option 2:
        //  Pick the current element if it does not exceed the target
        int pick = 0;
        if (arr[idx] <= target)
        {
            pick = memoCntWays(idx - 1, arr, dp, target - arr[idx]);
        }

        // Store and return the result for current subproblem
        return dp[idx][target] = pick + notPick;
    }

    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();

        // Initialize memoization table with -1 (uncomputed)
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return memoCntWays(n - 1, arr, dp, target);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// TABULATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution3
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();

        // dp[i][j]:
        // number of ways to get sum 'j' using first (i+1) elements
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // If arr[0] == 0,
        // two ways to make sum 0: pick or not pick
        if (arr[0] == 0)
        {
            dp[0][0] = 2;
        }
        else
        {
            dp[0][0] = 1;
        }

        // If arr[0] is within target and not zero,
        // one way to form sum arr[0]
        if (arr[0] != 0 && arr[0] <= target)
        {
            dp[0][arr[0]] = 1;
        }

        // Fill the dp table
        for (int idx = 1; idx < n; idx++)
        {
            for (int currSum = 0; currSum <= target; currSum++)
            {
                // Option 1: Do not include arr[idx] in the subset
                int notTake = dp[idx - 1][currSum];

                // Option 2: Include arr[idx] in the subset (if possible)
                int take = 0;
                if (arr[idx] <= currSum)
                {
                    take = dp[idx - 1][currSum - arr[idx]];
                }

                // Total ways: sum of both options
                dp[idx][currSum] = take + notTake;
            }
        }

        return dp[n - 1][target];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// SPACE OPTIMIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution4
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();

        // prevDP[j]:
        // number of ways to get sum 'j' using first i elements (previous row)
        vector<int> prevDP(target + 1, 0);

        // tempDP[j]:
        // number of ways to get sum 'j' using first (i+1) elements (current row)
        vector<int> tempDP(target + 1, 0);

        // Base case initialization for the first element (arr[0]):
        // If arr[0] == 0,
        // there are two ways to get sum 0: pick or not pick the zero
        if (arr[0] == 0)
        {
            prevDP[0] = 2;
        }
        else
        {
            // If arr[0] != 0,
            // only one way to get sum 0: do not pick arr[0]
            prevDP[0] = 1;
        }

        // If arr[0] is not zero and less than or equal to target,
        // there is one way to get sum arr[0]: pick arr[0]
        if (arr[0] != 0 && arr[0] <= target)
        {
            prevDP[arr[0]] = 1;
        }

        // Iterate over the rest of the elements
        for (int idx = 1; idx < n; idx++)
        {
            // For each possible sum from 0 to target
            for (int currSum = 0; currSum <= target; currSum++)
            {
                // Option 1: Do not include arr[idx] in the subset
                int notTake = prevDP[currSum];

                // Option 2: Include arr[idx] in the subset (if possible)
                int take = 0;
                if (arr[idx] <= currSum)
                {
                    // If arr[idx] can be included,
                    // add the number of ways to form (currSum - arr[idx])
                    take = prevDP[currSum - arr[idx]];
                }

                // Total number of ways
                // to form currSum using first (idx+1) elements
                tempDP[currSum] = take + notTake;
            }

            // Move current row to previous for the next iteration
            prevDP = tempDP;
        }

        return prevDP[target];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{

    vector<int> arr1 = {5, 2, 3, 10, 6, 8}; // OUTPUT: 3
    int target1 = 10;

    vector<int> arr2 = {35, 2, 8, 22}; // OUTPUT: 0
    int target2 = 1;

    vector<int> arr3 = {2, 5, 1, 4, 3}; // OUTPUT: 3
    int target3 = 10;

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << sol1.perfectSum(arr1, target1) << endl;
    cout << sol1.perfectSum(arr2, target2) << endl;
    cout << sol1.perfectSum(arr3, target3) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << sol2.perfectSum(arr1, target1) << endl;
    cout << sol2.perfectSum(arr2, target2) << endl;
    cout << sol2.perfectSum(arr3, target3) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << sol3.perfectSum(arr1, target1) << endl;
    cout << sol3.perfectSum(arr2, target2) << endl;
    cout << sol3.perfectSum(arr3, target3) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << sol4.perfectSum(arr1, target1) << endl;
    cout << sol4.perfectSum(arr2, target2) << endl;
    cout << sol4.perfectSum(arr3, target3) << endl;

    return 0;
}