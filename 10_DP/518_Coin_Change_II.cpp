/**
 *  @file: 518_Coin_Change_II.cpp
 *  @author: Avinash Yadav
 *  @date: 29-06-2025
 *  @link: https://leetcode.com/problems/coin-change-ii/description/
 *  @brief: You are given an integer array coins representing coins of different denominations and
            an integer amount representing a total amount of money.

            Return the number of combinations that make up that amount.
            If that amount of money cannot be made up by any combination of the coins, return 0.

            You may assume that you have an infinite number of each kind of coin.

            The answer is guaranteed to fit into a signed 32-bit integer.

            Example 1:
                Input: amount = 5, coins = [1,2,5]
                Output: 4
                Explanation: there are four ways to make up the amount:
                5=5
                5=2+2+1
                5=2+1+1+1
                5=1+1+1+1+1

            Example 2:
                Input: amount = 3, coins = [2]
                Output: 0
                Explanation: the amount of 3 cannot be made up just with coins of 2.

            Example 3:
                Input: amount = 10, coins = [10]
                Output: 1
 */

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    int recursiveWays(int idx, int amount, vector<int> &coins)
    {
        // Base case: If only the first coin is available
        // If amount is divisible by coins[0],
        // it's possible to form amount using only coins[0]
        if (idx == 0)
        {
            return (amount % coins[0] == 0);
        }

        // Option 1: Do not take the current coin
        int notTake = recursiveWays(idx - 1, amount, coins);

        // Option 2: Take the current coin (if possible)
        int take = 0;
        if (coins[idx] <= amount)
        {
            // Stay at idx
            // because we can use the same coin again (unlimited supply)
            take = recursiveWays(idx, amount - coins[idx], coins);
        }

        // Total ways = ways by taking + ways by not taking
        return take + notTake;
    }

    // Main function to be called
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        return recursiveWays(n - 1, amount, coins);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    int memoWays(int idx, int amount, vector<int> &coins,
                 vector<vector<int>> &dp)
    {
        // Base case: Only first coin available
        if (idx == 0)
        {
            return (amount % coins[0] == 0);
        }

        // Return cached result if already computed
        if (dp[idx][amount] != -1)
        {
            return dp[idx][amount];
        }

        // Option 1: Do not take the current coin
        int notTake = memoWays(idx - 1, amount, coins, dp);

        // Option 2: Take the current coin (if possible)
        int take = 0;
        if (coins[idx] <= amount)
        {
            take = memoWays(idx, amount - coins[idx], coins, dp);
        }

        // Store and return the result
        return dp[idx][amount] = take + notTake;
    }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        // dp[idx][amount]
        //   = number of ways to make 'amount' using coins[0..idx]
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return memoWays(n - 1, amount, coins, dp);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// TABULATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution3
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        // dp[i][t] =
        //    number of ways to make amount 't' using coins[0..i]
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base case: Fill the first row (using only coins[0])
        // For all t, if t is divisible by coins[0],
        // there is 1 way to form t using only coins[0]
        for (int t = 0; t <= amount; t++)
        {
            dp[0][t] = (t % coins[0] == 0);
        }

        // Build the table for all coins and all amounts
        for (int idx = 1; idx < n; idx++)
        {
            for (int t = 0; t <= amount; t++)
            {
                // Option 1: Do not take the current coin
                int notTake = dp[idx - 1][t];

                // Option 2: Take the current coin (if possible)
                int take = 0;
                if (coins[idx] <= t)
                {
                    // Use the same coin again, so stay at idx
                    take = dp[idx][t - coins[idx]];
                }

                // Total ways = ways by taking + ways by not taking
                dp[idx][t] = take + notTake;
            }
        }

        return dp[n - 1][amount];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// SPACE OPTIMIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
// This approach reduces the space complexity from O(n*amount) to O(amount).
// Instead of keeping a full 2D DP table, we only keep two 1D arrays:
// - prevDP: stores results for the previous coin
// - tempDP: stores results for the current coin

class Solution4
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        // prevDP[t]:
        //  number of ways to make amount 't'
        vector<int> prevDP(amount + 1, 0);
        // tempDP[t]:
        //  number of ways to make amount 't' 
        vector<int> tempDP(amount + 1, 0);

        // Base case: using only the first coin (coins[0])
        // For all t, if t is divisible by coins[0],
        // there is 1 way to form t
        for (int t = 0; t <= amount; t++)
        {
            prevDP[t] = (t % coins[0] == 0);
        }

        // For each coin starting from the second one
        for (int idx = 1; idx < n; idx++)
        {
            for (int t = 0; t <= amount; t++)
            {
                // Option 1: Do not take the current coin
                int notTake = prevDP[t];

                // Option 2: Take the current coin (if possible)
                int take = 0;
                if (coins[idx] <= t)
                {
                    // Use the same coin again,
                    // so stay at idx (use tempDP)
                    take = tempDP[t - coins[idx]];
                }

                // Total ways = ways by taking + ways by not taking
                tempDP[t] = take + notTake;
            }

            // Move to the next coin:
            // current results become previous
            prevDP = tempDP;
        }

        return prevDP[amount];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 5; // OUTPUT: 4

    vector<int> coins2 = {2};
    int amount2 = 3; // OUTPUT: 0

    vector<int> coins3 = {10};
    int amount3 = 10; // OUTPUT: 1

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << sol1.change(amount1, coins1) << endl;
    cout << sol1.change(amount2, coins2) << endl;
    cout << sol1.change(amount3, coins3) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << sol2.change(amount1, coins1) << endl;
    cout << sol2.change(amount2, coins2) << endl;
    cout << sol2.change(amount3, coins3) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << sol3.change(amount1, coins1) << endl;
    cout << sol3.change(amount2, coins2) << endl;
    cout << sol3.change(amount3, coins3) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << sol4.change(amount1, coins1) << endl;
    cout << sol4.change(amount2, coins2) << endl;
    cout << sol4.change(amount3, coins3) << endl;

    return 0;
}