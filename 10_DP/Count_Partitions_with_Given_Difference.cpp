/**
 *  @file: Count_Partitions_with_Given_Difference.cpp
 *  @author: Avinash Yadav
 *  @date: 26-06-2025
 *  @link:
 *  @brief:
 */

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    int recursionCntWays(int idx, vector<int> &arr, int target)
    {
        if (idx == 0)
        {
            if (target == 0 && arr[0] == 0)
            {
                return 2;
            }

            if (target == 0 || arr[0] == target)
            {
                return 1;
            }

            return 0;
        }
        int notPick = recursionCntWays(idx - 1, arr, target);

        int pick = 0;
        if (arr[idx] <= target)
        {
            pick = recursionCntWays(idx - 1, arr, target - arr[idx]);
        }

        return pick + notPick;
    }

    int countPartitions(vector<int> &arr, int d)
    {
        int n = arr.size();

        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if ((totalSum - d) < 0 || (totalSum - d) & 1)
        {
            return 0;
        }

        int target = (totalSum - d) / 2;

        return recursionCntWays(n - 1, arr, target);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    int memoCntWays(int idx, vector<int> &arr, vector<vector<int>> &dp, int target)
    {
        if (idx == 0)
        {
            if (target == 0 && arr[0] == 0)
            {
                return 2;
            }

            if (target == 0 || arr[0] == target)
            {
                return 1;
            }

            return 0;
        }

        if (dp[idx][target] != -1)
        {
            return dp[idx][target];
        }

        int notPick = memoCntWays(idx - 1, arr, dp, target);

        int pick = 0;
        if (arr[idx] <= target)
        {
            pick = memoCntWays(idx - 1, arr, dp, target - arr[idx]);
        }

        return dp[idx][target] = pick + notPick;
    }

    int countPartitions(vector<int> &arr, int d)
    {
        int n = arr.size();

        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if ((totalSum - d) < 0 || (totalSum - d) & 1)
        {
            return 0;
        }

        int target = (totalSum - d) / 2;

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
    int countPartitions(vector<int> &arr, int d)
    {
        int n = arr.size();

        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if ((totalSum - d) < 0 || (totalSum - d) & 1)
        {
            return 0;
        }

        int target = (totalSum - d) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        if (arr[0] == 0)
        {
            dp[0][0] = 2;
        }
        else
        {
            dp[0][0] = 1;
        }

        if (arr[0] != 0 && arr[0] <= target)
        {
            dp[0][arr[0]] = 1;
        }

        for (int idx = 1; idx < n; idx++)
        {
            for (int currSum = 0; currSum <= target; currSum++)
            {
                int notTake = dp[idx - 1][currSum];

                int take = 0;
                if (arr[idx] <= currSum)
                {
                    take = dp[idx - 1][currSum - arr[idx]];
                }

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
    int countPartitions(vector<int> &arr, int d)
    {
        int n = arr.size();

        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if ((totalSum - d) < 0 || (totalSum - d) & 1)
        {
            return 0;
        }

        int target = (totalSum - d) / 2;

        vector<int> prevDP(target + 1, 0);
        vector<int> tempDP(target + 1, 0);

        if (arr[0] == 0)
        {
            prevDP[0] = 2;
        }
        else
        {
            prevDP[0] = 1;
        }

        if (arr[0] != 0 && arr[0] <= target)
        {
            prevDP[arr[0]] = 1;
        }

        for (int idx = 1; idx < n; idx++)
        {
            for (int currSum = 0; currSum <= target; currSum++)
            {
                int notTake = prevDP[currSum];

                int take = 0;
                if (arr[idx] <= currSum)
                {
                    take = prevDP[currSum - arr[idx]];
                }

                tempDP[currSum] = take + notTake;
            }

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

    vector<int> arr1 = {5, 2, 6, 4}; // OUTPUT: 1
    int d1 = 3;

    vector<int> arr2 = {1, 1, 1, 1}; // OUTPUT: 6
    int d2 = 0;

    vector<int> arr3 = {1, 2, 1, 0, 1, 3, 3}; // OUTPUT: 2
    int d3 = 11;

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << sol1.countPartitions(arr1, d1) << endl;
    cout << sol1.countPartitions(arr2, d2) << endl;
    cout << sol1.countPartitions(arr3, d3) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << sol2.countPartitions(arr1, d1) << endl;
    cout << sol2.countPartitions(arr2, d2) << endl;
    cout << sol2.countPartitions(arr3, d3) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << sol3.countPartitions(arr1, d1) << endl;
    cout << sol3.countPartitions(arr2, d2) << endl;
    cout << sol3.countPartitions(arr3, d3) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << sol4.countPartitions(arr1, d1) << endl;
    cout << sol4.countPartitions(arr2, d2) << endl;
    cout << sol4.countPartitions(arr3, d3) << endl;

    return 0;
}