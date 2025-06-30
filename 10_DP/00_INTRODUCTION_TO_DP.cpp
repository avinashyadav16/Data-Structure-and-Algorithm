/**
 *  @file: 00_INTRODUCTION_TO_DP.cpp
 *  @author: Avinash Yadav
 *  @brief: fibnoci: from recursion to dp.
 */

#include <bits/stdc++.h>
using namespace std;

int recursionApproach(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }

    return recursionApproach(n - 1) + recursionApproach(n - 2);
}

int dpMemoApproach(int n, vector<int> &dp)
{
    if (n == 1 || n == 0)
    {
        return dp[n] = n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = dpMemoApproach(n - 1, dp) + dpMemoApproach(n - 2, dp);
}

int dpTabuApproach(int n)
{
    int prev2 = 0;
    int prev1 = 1;

    if (n == 0)
    {
        return prev2;
    }
    else if (n == 1)
    {
        return prev1;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;

            prev2 = prev1;
            prev1 = curr;
        }
    }

    return prev1;
}

int main()
{
    cout << "Enter Value of N: ";
    int n;
    cin >> n;

    cout << "Solution Using Recusion:" << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << recursionApproach(i) << " ";
    }
    cout << endl;

    //////////////////////////////////////////////////////////////////////////

    vector<int> dp(n + 1, -1);

    cout << "\nSolution Using DP(Memoization):" << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << dpMemoApproach(i, dp) << " ";
    }
    cout << endl;

    //////////////////////////////////////////////////////////////////////////

    cout << "\nSolution Using DP(Tabulation): " << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << dpTabuApproach(i) << " ";
    }

    return 0;
}