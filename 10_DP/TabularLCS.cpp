/**
 *  @file: TabularLCS.cpp
 *  @author: Avinash Yadav
 *  @date: 09-06-2025
 *  @link:
 *  @brief:
 */

#include <bits/stdc++.h>
using namespace std;

// Bottom-Up (Tabulation)
int findLCS(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

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

    return dp[n][m];
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