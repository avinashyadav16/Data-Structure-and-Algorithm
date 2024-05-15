/**
 *  @file: Question_03_Rod_Cutting.cpp
 *  @author: Avinash Yadav
 *  @brief: Provide the implementation of the problems Rod Cutting
 *  @date: 12-04-2024
 */

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum obtainable value by cutting up a rod of length n
int rodCutting(vector<int> &prices, int n)
{
    // dp vector with size (n + 1) and fill it with 0
    vector<int> dp(n + 1, 0);

    // Iterate through each rod length from 1 to n
    for (int i = 1; i <= n; ++i)
    {
        // Initialize maxVal as INT_MIN
        int maxVal = INT_MIN;

        // Iterate through each possible cut position
        for (int j = 1; j <= i; ++j)
        {
            // Update maxVal with the maximum
            // between its current value and the price of the cut of length j plus dp[i - j]
            maxVal = max(maxVal, prices[j] + dp[i - j]);
        }

        // Update dp[i] with maxVal
        dp[i] = maxVal;
    }

    // Return the maximum obtainable value for rod of length n
    return dp[n];
}

int main()
{
    // Prices for each rod length
    vector<int> prices = {0, 1, 5, 8, 9, 10, 17, 17, 20};

    // Llength of the rod
    int n = 8;

    cout << "==> Rod Cutting Problem <==" << endl;

    // Print the rod lengths and their respective prices
    cout << "\nRod Lengths and Prices: ";
    for (int i = 1; i <= n; ++i)
    {
        cout << i << ":" << prices[i] << " ";
    }
    cout << endl;

    // Maximum obtainable value for rod of length n
    cout << "\nMaximum Obtainable Value: " << rodCutting(prices, n) << endl;

    return 0;
}