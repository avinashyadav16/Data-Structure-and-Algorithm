/**
 *  @file: Question_02_Coin_Change.cpp
 *  @author: Avinash Yadav
 *  @brief: Provide the implementation of the problems Coin Change using a DP approach
 *  @date: 12-04-2024
 */

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of coins
int coinChange(vector<int> &coins, int amount)
{
    // Initialize a vector dp with size (amount + 1) and fill it with (amount + 1)
    vector<int> dp(amount + 1, amount + 1);

    // Base case: To make an amount of 0, 0 coins are required
    dp[0] = 0;

    // Iterate from 1 to the given amount
    for (int i = 1; i <= amount; ++i)
    {
        // Iterate through each coin denomination
        for (int coin : coins)
        {
            // Check if the coin denomination is less than or equal to the current amount
            if (coin <= i)
            {
                // Update dp[i] with the minimum between its current value and dp[i - coin] + 1
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If dp[amount] is greater than the given amount, return -1
    // Otherwise, return dp[amount] (minimum number of coins required)
    return dp[amount] > amount ? -1 : dp[amount];
}

int main()
{
    vector<int> coins = {1, 5, 6, 9};
    int amount = 11;

    cout << "==> Coin Change Problem <==" << endl;
    cout << "Coin Denominations Are: ";
    for (int coin : coins)
    {
        cout << coin << " ";
    }
    cout << endl;
    cout << "Required Amount: " << amount << endl;
    
    
    cout << "Minimum number of coins required: " << coinChange(coins, amount) << endl;

    return 0;
}