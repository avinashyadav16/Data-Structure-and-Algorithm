/**
 *  @file: 0_1_Knapsack.cpp
 *  @author: Avinash Yadav
 *  @date: 27-06-2025
 *  @link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
 *  @brief: Given n items, each with a specific weight and value, and a knapsack with a capacity of W,
            the task is to put the items in the knapsack such that the sum of weights of the items <= W and
            the sum of values associated with them is maximized.

            Note: You can either place an item entirely in the bag or leave it out entirely.
            Also, each item is available in single quantity.

            Examples :
            Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
            Output: 3
            Explanation: Choose the last item, which weighs 1 unit and has a value of 3.

            Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6]
            Output: 0
            Explanation: Every item has a weight exceeding the knapsack's capacity (3).

            Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3]
            Output: 80
            Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.
 */

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    // idx: current item index (0-based)
    // W: remaining capacity of knapsack
    // val: vector of item values
    // wt: vector of item weights
    int recursionMaxProfit(int idx, int W, vector<int> &val,
                           vector<int> &wt)
    {
        // Base case: Only one item left (idx == 0)
        if (idx == 0)
        {
            // If the first item's weight fits,
            // take its value
            if (wt[0] <= W)
            {
                return val[0];
            }
            else
            {
                // Otherwise, can't take it
                return 0;
            }
        }

        // Option 1: Do not take the current item
        int notTake = recursionMaxProfit(idx - 1, W, val, wt);

        // Option 2: Take the current item (if it fits)
        int take = INT_MIN;
        if (wt[idx] <= W)
        {
            // Add current item's value and
            // solve for reduced capacity and items
            take = val[idx] +
                   recursionMaxProfit(idx - 1, W - wt[idx], val, wt);
        }

        // Return the maximum of
        // taking or not taking the current item
        return max(take, notTake);
    }

    // Main function to be called for knapsack
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size(); // Number of items

        // Start recursion from the last item and full capacity
        return recursionMaxProfit(n - 1, W, val, wt);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    // idx: current item index
    // W: remaining weight capacity
    // val: vector of item values
    // wt: vector of item weights
    // dp: memoization table (dp[idx][W] stores max profit for idx and W)
    int memoMaxProfit(int idx, int W, vector<int> &val, vector<int> &wt,
                      vector<vector<int>> &dp)
    {
        // Base case: only one item left (idx == 0)
        if (idx == 0)
        {
            // If the first item's weight fits,
            // take its value; otherwise, profit is 0
            if (wt[0] <= W)
            {
                return val[0];
            }
            else
            {
                return 0;
            }
        }

        // Check if result is already computed (memoization)
        if (dp[idx][W] != -1)
        {
            return dp[idx][W];
        }

        // Option 1: Do not take the current item
        int notTake = memoMaxProfit(idx - 1, W, val, wt, dp);

        // Option 2: Take the current item (if it fits)
        int take = INT_MIN;
        if (wt[idx] <= W)
        {
            // Add current item's value and
            // solve subproblem for reduced capacity
            take = val[idx] +
                   memoMaxProfit(idx - 1, W - wt[idx], val, wt, dp);
        }

        // Store and
        // return the maximum of taking or not taking the item
        return dp[idx][W] = max(take, notTake);
    }

    // Main function to solve the knapsack problem
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size(); // Number of items

        // Initialize memoization table with -1 (uncomputed)
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

        // Start recursion from the last item and full capacity
        return memoMaxProfit(n - 1, W, val, wt, dp);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// TABULATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution3
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();

        // dp[i][j] will store the maximum value
        // for the first i items and capacity j
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // Base case:
        // Fill the first row (only considering the first item)
        // If the first item's weight is less than or equal to
        // the current capacity, take its value
        for (int i = wt[0]; i <= W; i++)
        {
            dp[0][i] = val[0];
        }

        // Build the dp table iteratively
        for (int idx = 1; idx < n; idx++)
        {
            for (int bgWt = 0; bgWt <= W; bgWt++)
            {
                // Option 1: Do not take the current item
                int notTake = dp[idx - 1][bgWt];

                // Option 2: Take the current item (if it fits)
                int take = INT_MIN;
                if (wt[idx] <= bgWt)
                {
                    take = val[idx] +
                           dp[idx - 1][bgWt - wt[idx]];
                }

                // Store the maximum of taking or not taking
                dp[idx][bgWt] = max(take, notTake);
            }
        }

        // Maximum value for all items and full capacity
        return dp[n - 1][W];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// SPACE OPTIMIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
// This approach reduces the space complexity from O(n*W) to O(W).
// Instead of maintaining a full 2D DP table, we only keep two 1D arrays:
// - prevDP: stores results for the previous item
// - tempDP: stores results for the current item
// After each item, we update prevDP to be tempDP for the next iteration.

class Solution4
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();

        // prevDP[j]: 
        // max value for capacity j using items up to previous index
        vector<int> prevDP(W + 1, 0);

        // tempDP[j]:
        // max value for capacity j using items up to current index
        vector<int> tempDP(W + 1, 0);

        // Base case: Only the first item is considered
        // For all capacities >= wt[0], we can take the first item
        for (int i = wt[0]; i <= W; i++)
        {
            prevDP[i] = val[0];
        }

        // Iterate over all items starting from the second
        for (int idx = 1; idx < n; idx++)
        {
            for (int bgWt = 0; bgWt <= W; bgWt++)
            {
                // Option 1: Do not take the current item
                int notTake = prevDP[bgWt];

                // Option 2: Take the current item (if it fits)
                int take = INT_MIN;
                if (wt[idx] <= bgWt)
                {
                    // Add current item's value and
                    // use the result for reduced capacity
                    take = val[idx] + prevDP[bgWt - wt[idx]];
                }

                // Store the maximum of taking or not taking the item
                tempDP[bgWt] = max(take, notTake);
            }

            // Move to the next item: current results become previous
            prevDP = tempDP;
        }

        // The answer is the max value for full capacity using all items
        return prevDP[W];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    int w1 = 4;
    vector<int> val1 = {1, 2, 3};
    vector<int> wt1 = {4, 5, 1}; // OUTPUT: 3

    int w2 = 3;
    vector<int> val2 = {1, 2, 3};
    vector<int> wt2 = {4, 5, 6}; // OUTPUT: 0

    int w3 = 5;
    vector<int> val3 = {10, 40, 30, 50};
    vector<int> wt3 = {5, 4, 2, 3}; // OUTPUT: 80

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << sol1.knapsack(w1, val1, wt1) << endl;
    cout << sol1.knapsack(w2, val2, wt2) << endl;
    cout << sol1.knapsack(w3, val3, wt3) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << sol2.knapsack(w1, val1, wt1) << endl;
    cout << sol2.knapsack(w2, val2, wt2) << endl;
    cout << sol2.knapsack(w3, val3, wt3) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << sol3.knapsack(w1, val1, wt1) << endl;
    cout << sol3.knapsack(w2, val2, wt2) << endl;
    cout << sol3.knapsack(w3, val3, wt3) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << sol4.knapsack(w1, val1, wt1) << endl;
    cout << sol4.knapsack(w2, val2, wt2) << endl;
    cout << sol4.knapsack(w3, val3, wt3) << endl;

    return 0;
}