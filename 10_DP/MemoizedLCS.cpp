/**
 *  @file: MemoizedLCS.cpp
 *  @author: Avinash Yadav
 *  @date: 09-06-2025
 *  @link:
 *  @brief:
 */

#include <bits/stdc++.h>
using namespace std;

// Top-Down Dynamic Programming approach with Memoization.
int memoizedLCS(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (str1[i - 1] == str2[j - 1])
    {
        return dp[i][j] = 1 + memoizedLCS(i - 1, j - 1, str1, str2, dp);
    }
    else
    {
        return dp[i][j] = max(memoizedLCS(i - 1, j, str1, str2, dp), memoizedLCS(i, j - 1, str1, str2, dp));
    }
}

int findLCS(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Top-Down (Memoization)
    int maxLCS = memoizedLCS(n, m, s1, s2, dp);

    // Print the dp table
    cout << "\nDP Table:\n";
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            cout << setw(3) << dp[i][j] << " ";
        }
        cout << endl;
    }

    return maxLCS;
}

int main()
{
    string str1;
    cin >> str1;

    string str2;
    cin >> str2;

    cout << findLCS(str1, str2) << endl;

    return 0;
}