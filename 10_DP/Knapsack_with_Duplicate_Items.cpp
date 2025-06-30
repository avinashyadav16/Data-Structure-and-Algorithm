/**
*  @file: Knapsack_with_Duplicate_Items.cpp
*  @author: Avinash Yadav
*  @date: 30-06-2025
*  @link: https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
*  @brief: Given a set of items, each with a weight and a value, represented by the array wt and val respectively.
            Also, a knapsack with a weight limit capacity.
            The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
            Note: Each item can be taken any number of times.

            Examples:
                Input: val = [1, 1], wt = [2, 1], capacity = 3
                Output: 3
                Explanation: The optimal choice is to pick the 2nd element 3 times.

                Input: val[] = [6, 1, 7, 7], wt[] = [1, 3, 4, 5], capacity = 8
                Output: 48
                Explanation: The optimal choice is to pick the 1st element 8 times.

                Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
                Output: 0
                Explanation: We can't pick any element .hence, total profit is 0.
*/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// RECURSION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution1
{
public:
    int recursionMaxCapacity(int idx, vector<int> &val,
                             vector<int> &wt, int capacity)
    {
        // Base case: Only one type of item left (idx == 0)
        // We can take as many as fit into the remaining capacity
        if (idx == 0)
        {
            return (capacity / wt[0]) * val[0];
        }

        // Option 1: Do not take the current item
        int notTake = recursionMaxCapacity(idx - 1, val, wt, capacity);

        // Option 2: Take the current item (if it fits)
        int take = INT_MIN;
        if (wt[idx] <= capacity)
        {
            // Add the value of the current item and
            // recurse with reduced capacity
            take = val[idx] +
                   recursionMaxCapacity(idx, val, wt, capacity - wt[idx]);
        }

        // Return the maximum of taking or not taking the current item
        return max(take, notTake);
    }

    // Main function to start the recursion
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        // Start recursion from the last item
        return recursionMaxCapacity(n - 1, val, wt, capacity);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// MEMOIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    int memoMaxCapacity(int idx, vector<int> &val,
                        vector<int> &wt, int capacity, vector<vector<int>> &dp)
    {
        // Base case: Only the first item is available
        if (idx == 0)
        {
            // Take as many of item 0 as possible
            return (((int)capacity / wt[0]) * val[0]);
        }

        // Return cached result if already computed
        if (dp[idx][capacity] != -1)
        {
            return dp[idx][capacity];
        }

        // Option 1: Do not take the current item
        int notTake = memoMaxCapacity(idx - 1, val, wt, capacity, dp);

        // Option 2: Take the current item (if it fits)
        int take = INT_MIN;
        if (wt[idx] <= capacity)
        {
            // Since it's unbounded, stay at idx
            take = val[idx] +
                   memoMaxCapacity(idx, val, wt, capacity - wt[idx], dp);
        }

        // Store and return the maximum of both choices
        return dp[idx][capacity] = max(take, notTake);
    }

    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        // DP table: n items x (capacity+1) capacities, initialized to -1
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return memoMaxCapacity(n - 1, val, wt, capacity, dp);
    }
};

//////////////////////////////////////////////////////////////////////////////////
// TABULATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution3
{
public:
    // Bottom-up DP for Unbounded Knapsack
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();
        // DP table:
        //  n items x (capacity+1) capacities, initialized to 0
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        // Fill base case: only item 0 available
        for (int w = wt[0]; w <= capacity; w++)
        {
            // Take as many of item 0 as possible
            dp[0][w] = (((int)w / wt[0]) * val[0]);
        }

        // Build the table for all items and capacities
        for (int idx = 1; idx < n; idx++)
        {
            for (int w = 0; w <= capacity; w++)
            {
                // Option 1: Do not take current item
                int notTake = dp[idx - 1][w];

                // Option 2: Take current item (if it fits)
                int take = INT_MIN;
                if (wt[idx] <= w)
                {
                    // Stay at idx for unbounded
                    take = val[idx] + dp[idx][w - wt[idx]];
                }

                // Store the best of both choices
                dp[idx][w] = max(take, notTake);
            }
        }

        return dp[n - 1][capacity];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// SPACE OPTIMIZATION APPROACH:
//////////////////////////////////////////////////////////////////////////////////
class Solution4
{
public:
    // Optimized DP using two 1D arrays to save space
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        int n = val.size();

        // prevDP: results for previous item
        // tempDP: results for current item
        vector<int> prevDP(capacity + 1, 0);
        vector<int> tempDP(capacity + 1, 0);

        // Base case: only item 0 available
        for (int w = wt[0]; w <= capacity; w++)
        {
            prevDP[w] = (((int)w / wt[0]) * val[0]);
        }

        // Build up for each item
        for (int idx = 1; idx < n; idx++)
        {
            for (int w = 0; w <= capacity; w++)
            {
                // Option 1: Do not take current item
                int notTake = prevDP[w];

                // Option 2: Take current item (if it fits)
                int take = INT_MIN;
                if (wt[idx] <= w)
                {
                    take = val[idx] + tempDP[w - wt[idx]];
                }

                tempDP[w] = max(take, notTake);
            }

            // Move to next item: current becomes previous
            prevDP = tempDP;
        }

        return prevDP[capacity];
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    int capacity1 = 3;
    vector<int> val1 = {1, 1};
    vector<int> wt1 = {2, 1}; // OUTPUT: 3

    int capacity2 = 8;
    vector<int> val2 = {6, 1, 7, 7};
    vector<int> wt2 = {1, 3, 4, 5}; // OUTPUT: 48

    int capacity3 = 1;
    vector<int> val3 = {6, 8, 7, 100};
    vector<int> wt3 = {2, 3, 4, 5}; // OUTPUT: 0

    cout << "By Recursion:" << endl;
    Solution1 sol1;
    cout << sol1.knapSack(val1, wt1, capacity1) << endl;
    cout << sol1.knapSack(val2, wt2, capacity2) << endl;
    cout << sol1.knapSack(val3, wt3, capacity3) << endl;

    cout << "By Memoization:" << endl;
    Solution2 sol2;
    cout << sol2.knapSack(val1, wt1, capacity1) << endl;
    cout << sol2.knapSack(val2, wt2, capacity2) << endl;
    cout << sol2.knapSack(val3, wt3, capacity3) << endl;

    cout << "By Tabulation:" << endl;
    Solution3 sol3;
    cout << sol3.knapSack(val1, wt1, capacity1) << endl;
    cout << sol3.knapSack(val2, wt2, capacity2) << endl;
    cout << sol3.knapSack(val3, wt3, capacity3) << endl;

    cout << "By Space Optimization:" << endl;
    Solution4 sol4;
    cout << sol4.knapSack(val1, wt1, capacity1) << endl;
    cout << sol4.knapSack(val2, wt2, capacity2) << endl;
    cout << sol4.knapSack(val3, wt3, capacity3) << endl;

    return 0;
}