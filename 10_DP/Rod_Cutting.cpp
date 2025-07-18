/**
*  @file: Rod_Cutting.cpp
*  @author: Avinash Yadav
*  @date: 30-06-2025
*  @link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1
*  @brief: Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i.
            Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

            Note: n = size of price, and price[] is 1-indexed array.

            Example:
                Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
                Output: 22
                Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.

                Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
                Output: 24
                Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1] = 8*3 = 24.

                Input: price[] = [3]
                Output: 3
                Explanation: There is only 1 way to pick a piece of length 1.
*/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    // idx: current index in price array (corresponds to rod length idx+1)
    // N: remaining length of the rod
    // price: vector containing prices for each length
    int recursionMaxProfit(int idx, int N, vector<int> &price)
    {
        // Base case: Only pieces of length 1 can be taken
        if (idx == 0)
        {
            // Take as many pieces of length 1 as possible
            return N * price[0];
        }

        // Option 1: Do not take the current piece length (idx+1)
        int notTake = recursionMaxProfit(idx - 1, N, price);

        // Option 2: Take the current piece length (if possible)
        int rodLen = idx + 1; // Current piece length
        int take = INT_MIN;
        if (rodLen <= N)
        {
            // Take this piece and solve for the remaining rod
            take = price[idx] + recursionMaxProfit(idx, N - rodLen, price);
        }

        // Return the maximum of taking or not taking the current piece
        return max(take, notTake);
    }

    int cutRod(vector<int> &price)
    {
        int n = price.size(); // Total length of the rod

        // Start recursion from the last index (largest piece length)
        return recursionMaxProfit(n - 1, n, price);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    // idx: current index in price array (piece length - 1)
    // N: remaining rod length
    // price: price list for each piece length
    // dp: memoization table, dp[idx][N] stores max profit for idx and N
    int memoMaxProfit(int idx, int N, vector<int> &price,
                      vector<vector<int>> &dp)
    {
        // Base case: only length-1 pieces left
        if (idx == 0)
        {
            // All remaining rod must be cut into length-1 pieces
            return N * price[0];
        }

        // Check if already computed
        if (dp[idx][N] != -1)
        {
            return dp[idx][N];
        }

        // Option 1: Do not take current piece length
        int notTake = memoMaxProfit(idx - 1, N, price, dp);

        // Current piece length (1-based)
        int rodLen = idx + 1;

        int take = INT_MIN;
        // Option 2: Take current piece length (if possible)
        if (rodLen <= N)
        {
            // Add price of current piece and solve for remaining rod
            take = price[idx] +
                   memoMaxProfit(idx, N - rodLen, price, dp);
        }

        // Store and return the best of both options
        return dp[idx][N] = max(take, notTake);
    }

    int cutRod(vector<int> &price)
    {
        // Total rod length
        int n = price.size();

        // dp[i][j]:
        // max profit using first (i+1) piece sizes to cut rod of length j
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // Start from the largest piece size and full rod length
        return memoMaxProfit(n - 1, n, price, dp);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// TABULATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution3
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();

        // dp[i][j]:
        //  max profit using first (i+1) piece sizes to cut rod of length j
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Base case: Only pieces of length 1 (idx=0) can be used
        // For any rod length N, the best is to take N pieces of length 1
        for (int N = 0; N <= n; N++)
        {
            dp[0][N] = N * price[0];
        }

        // Build the table for all piece sizes (idx) and rod lengths (N)
        for (int idx = 1; idx < n; idx++)
        {
            int rodLen = idx + 1; // Current piece length (1-based)
            for (int N = 0; N <= n; N++)
            {
                // Option 1: Do not take the current piece length
                int notTake = dp[idx - 1][N];

                // Option 2: Take the current piece length (if possible)
                int take = INT_MIN;
                if (rodLen <= N)
                {
                    // Take this piece and solve for the remaining rod
                    take = price[idx] + dp[idx][N - rodLen];
                }

                // Store the best of both options
                dp[idx][N] = max(take, notTake);
            }
        }

        return dp[n - 1][n];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// SPACE OPTIMIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution4
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();

        // prevDP[N]:
        // stores the maximum profit for rod length N using pieces up to previous index
        vector<int> prevDP(n + 1, 0);
        // tempDP[N]:
        // temporary array to store current computations for rod length N
        vector<int> tempDP(n + 1, 0);

        // Base case: Only pieces of length 1 (index 0) can be used
        // For any rod length N, the best is to take N pieces of length 1
        for (int N = 0; N <= n; N++)
        {
            prevDP[N] = N * price[0];
        }

        // Iterate over all piece sizes starting from index 1
        // (piece length = idx + 1)
        for (int idx = 1; idx < n; idx++)
        {
            int rodLen = idx + 1; // Current piece length (1-based)

            for (int N = 0; N <= n; N++)
            {
                // Option 1: Do not take the current piece length
                int notTake = prevDP[N];

                // Option 2: Take the current piece length (if possible)
                int take = INT_MIN;
                if (rodLen <= N)
                {
                    // Use prevDP for the previous state, not tempDP
                    take = price[idx] + prevDP[N - rodLen];
                }

                // Store the best of both options in tempDP
                tempDP[N] = max(take, notTake);
            }

            // Update prevDP for the next iteration
            prevDP = tempDP;
        }

        return prevDP[n];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    vector<int> price1 = {1, 5, 8, 9, 10, 17, 17, 20}; // OUTPUT: 22

    vector<int> price2 = {3, 5, 8, 9, 10, 17, 17, 20}; // OUTPUT: 24

    vector<int> price3 = {3}; // OUTPUT: 3

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << sol1.cutRod(price1) << endl;
    cout << sol1.cutRod(price2) << endl;
    cout << sol1.cutRod(price3) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << sol2.cutRod(price1) << endl;
    cout << sol2.cutRod(price2) << endl;
    cout << sol2.cutRod(price3) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << sol3.cutRod(price1) << endl;
    cout << sol3.cutRod(price2) << endl;
    cout << sol3.cutRod(price3) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << sol4.cutRod(price1) << endl;
    cout << sol4.cutRod(price2) << endl;
    cout << sol4.cutRod(price3) << endl;

    return 0;
}