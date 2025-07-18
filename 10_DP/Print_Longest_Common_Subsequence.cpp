/**
*  @file: Print_Longest_Common_Subsequence.cpp
*  @author: Avinash Yadav
*  @date: 01-07-2025
*  @link: https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383?leftPanelTabValue=PROBLEM
*  @brief: You are given two strings ‘s1’ and ‘s2’.
            Return the longest common subsequence of these strings.
            If there’s no such string, return an empty string.
            If there are multiple possible answers, return any such string.

            Note:
            Longest common subsequence of string ‘s1’ and ‘s2’ is the longest subsequence of ‘s1’ that is also a subsequence of ‘s2’.
            A ‘subsequence’ of ‘s1’ is a string that can be formed by deleting one or more (possibly zero) characters from ‘s1’.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findLCS(int n, int m, string &s1, string &s2)
    {
        // dp[i][j] will store the length of LCS
        // of s1[0..i-1] and s2[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Build the dp table in bottom-up manner
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    // If characters match,
                    // increment the count from previous indices
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    // Otherwise,
                    // take the maximum from
                    // either excluding current char from s1 or s2
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Reconstruct the LCS string from the dp table
        int i = n, j = m;
        string res = "";

        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                // If characters match,
                // include this character in result
                res += s1[i - 1];

                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                // Move in the direction of greater value
                i--;
            }
            else
            {
                j--;
            }
        }

        // The result is built backwards, so reverse it
        reverse(res.begin(), res.end());

        return res;
    }
};
