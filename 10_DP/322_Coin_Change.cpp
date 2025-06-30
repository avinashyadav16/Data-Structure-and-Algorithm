/**
*  @file: 322_Coin_Change.cpp
*  @author: Avinash Yadav
*  @date: 29-06-2025
*  @link: https://leetcode.com/problems/coin-change/description/
*  @brief: You are given an integer array coins representing coins of different denominations
            and an integer amount representing a total amount of money.

            Return the fewest number of coins that you need to make up that amount.
            If that amount of money cannot be made up by any combination of the coins, return -1.

            You may assume that you have an infinite number of each kind of coin.

            Example 1:
                Input: coins = [1,2,5], amount = 11
                Output: 3
                Explanation: 11 = 5 + 5 + 1

            Example 2:
                Input: coins = [2], amount = 3
                Output: -1

            Example 3:
                Input: coins = [1], amount = 0
                Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    // idx: current index in coins array
    // coins: vector of coin denominations
    // amount: remaining amount to be made
    int recursiveMinCoins(int idx, vector<int> &coins, int amount)
    {
        // Base case:
        // If we are at the first coin (idx == 0)
        if (idx == 0)
        {
            // If the amount can be made using only this coin
            if (amount % coins[idx] == 0)
            {
                // Return the number of coins needed
                return amount / coins[idx];
            }
            else
            {
                // If not possible,
                // return a large number (acts as infinity)
                return 1e9;
            }
        }

        // Option 1:
        // Do not take the current coin, move to the previous coin
        int notTake = recursiveMinCoins(idx - 1, coins, amount);

        // Option 2:
        // Take the current coin (if possible), stay at the same index
        int take = INT_MAX;
        if (coins[idx] <= amount)
        {
            // Take the coin and reduce the amount
            // Note: Add 1 because we are taking one coin
            take = 1 + recursiveMinCoins(idx, coins, amount - coins[idx]);
        }

        // Return the minimum of taking or not taking the coin
        return min(take, notTake);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int ans = recursiveMinCoins(n - 1, coins, amount);

        // If answer is still a large number,
        // it means it's not possible to make the amount
        return (ans >= 1e9) ? -1 : ans;
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    // idx: current coin index
    // coins: list of coin denominations
    // amount: remaining amount to form
    // dp: memoization table
    int memoMinCoins(int idx, vector<int> &coins, int amount,
                     vector<vector<int>> &dp)
    {
        // Base case: only one coin type left
        if (idx == 0)
        {
            // If amount is divisible by the smallest coin,
            // return the number of coins needed
            if (amount % coins[idx] == 0)
            {
                return amount / coins[idx];
            }
            else
            {
                // Otherwise,
                // it's impossible to form the amount with this coin
                // Use a large number to represent "infinity"
                return 1e9;
            }
        }

        // Check if result is already computed
        if (dp[idx][amount] != -1)
        {
            return dp[idx][amount];
        }

        // Option 1: Do not take the current coin
        int notTake = memoMinCoins(idx - 1, coins, amount, dp);

        // Option 2: Take the current coin (if possible)
        int take = 1e9;
        if (coins[idx] <= amount)
        {
            // Take the coin and reduce the amount
            take = 1 +
                   memoMinCoins(idx, coins, amount - coins[idx], dp);
        }

        // Store and return the minimum of both options
        return dp[idx][amount] = min(take, notTake);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        // Initialize DP table with -1 (uncomputed)
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = memoMinCoins(n - 1, coins, amount, dp);

        // If answer is still "infinity", return -1 (not possible)
        return (ans >= 1e9) ? -1 : ans;
    }
};

//////////////////////////////////////////////////////////////////////////////////
// TABULATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////

class Solution3
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        // dp[i][amt]: min coins to make amt using coins[0..i]
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base case: using only the first coin
        for (int amt = 0; amt <= amount; amt++)
        {
            // If amt is divisible by coins[0],
            // we can use amt/coins[0] coins
            if (amt % coins[0] == 0)
            {
                dp[0][amt] = amt / coins[0];
            }
            else
            {
                // Impossible to form amt with coins[0] only
                dp[0][amt] = 1e9;
            }
        }

        // Build up the DP table
        for (int idx = 1; idx < n; idx++)
        {
            for (int amt = 0; amt <= amount; amt++)
            {
                // Option 1: Do not take current coin
                int notTake = dp[idx - 1][amt];

                // Option 2: Take current coin (if possible)
                int take = 1e9;
                if (coins[idx] <= amt)
                {
                    take = 1 + dp[idx][amt - coins[idx]];
                }

                // Take the minimum of both options
                dp[idx][amt] = min(take, notTake);
            }
        }

        // If answer is still 1e9, it's impossible to form amount
        int ans = dp[n - 1][amount];

        return (ans >= 1e9) ? -1 : ans;
    }
};

//////////////////////////////////////////////////////////////////////////////////
// SPACE OPTIMIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
// This approach reduces the space complexity from O(n*amount) to O(amount).
// Instead of keeping the entire DP table, we only keep two 1D arrays:
// - prevDP: stores results for the previous coin
// - tempDP: stores results for the current coin

class Solution4
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        // prevDP[amt]:
        // min coins to make amt using coins[0..idx-1]
        vector<int> prevDP(amount + 1, 0);
        
        // tempDP[amt]:
        // min coins to make amt using coins[0..idx]
        vector<int> tempDP(amount + 1, 0);

        // Base case: using only the first coin (coins[0])
        for (int amt = 0; amt <= amount; amt++)
        {
            // If amt is divisible by coins[0],
            // we can use amt/coins[0] coins
            if (amt % coins[0] == 0)
            {
                prevDP[amt] = amt / coins[0];
            }
            else
            {
                // Impossible to form amt with coins[0] only
                prevDP[amt] = 1e9;
            }
        }

        // Iterate over the rest of the coins
        for (int idx = 1; idx < n; idx++)
        {
            for (int amt = 0; amt <= amount; amt++)
            {
                // Option 1: Do not take the current coin
                int notTake = prevDP[amt];

                // Option 2: Take the current coin (if possible)
                int take = 1e9;
                if (coins[idx] <= amt)
                {
                    // Use tempDP for current row
                    // (since we can take the same coin multiple times)
                    take = 1 + tempDP[amt - coins[idx]];
                }

                // Store the minimum of both options
                tempDP[amt] = min(take, notTake);
            }

            // Move to the next coin:
            // current row becomes previous row
            prevDP = tempDP;
        }

        int ans = prevDP[amount];

        // If answer is still "infinity",
        // it's impossible to form the amount
        return (ans >= 1e9) ? -1 : ans;
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11; // OUTPUT: 3

    vector<int> coins2 = {2};
    int amount2 = 3; // OUTPUT: -1

    vector<int> coins3 = {1};
    int amount3 = 0; // OUTPUT: 0

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << sol1.coinChange(coins1, amount1) << endl;
    cout << sol1.coinChange(coins2, amount2) << endl;
    cout << sol1.coinChange(coins3, amount3) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << sol2.coinChange(coins1, amount1) << endl;
    cout << sol2.coinChange(coins2, amount2) << endl;
    cout << sol2.coinChange(coins3, amount3) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << sol3.coinChange(coins1, amount1) << endl;
    cout << sol3.coinChange(coins2, amount2) << endl;
    cout << sol3.coinChange(coins3, amount3) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << sol4.coinChange(coins1, amount1) << endl;
    cout << sol4.coinChange(coins2, amount2) << endl;
    cout << sol4.coinChange(coins3, amount3) << endl;

    return 0;
}