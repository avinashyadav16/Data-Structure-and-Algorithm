/**
*  @file: 1143_Longest_Common_Subsequence.cpp
*  @author: Avinash Yadav
*  @date: 01-07-2025
*  @link: https://leetcode.com/problems/longest-common-subsequence/description/
*  @brief: Given two strings text1 and text2, return the length of their longest common subsequence.
            If there is no common subsequence, return 0.
            A subsequence of a string is a new string generated from the original string
            with some characters (can be none) deleted without changing the relative order of the remaining characters.

            For example, "ace" is a subsequence of "abcde".
            A common subsequence of two strings is a subsequence that is common to both strings.

            Example 1:
                Input: text1 = "abcde", text2 = "ace"
                Output: 3
                Explanation: The longest common subsequence is "ace" and its length is 3.

            Example 2:
                Input: text1 = "abc", text2 = "abc"
                Output: 3
                Explanation: The longest common subsequence is "abc" and its length is 3.

            Example 3:
                Input: text1 = "abc", text2 = "def"
                Output: 0
                Explanation: There is no such common subsequence, so the result is 0.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to find the length of the longest common subsequence
int LCS(const string &X, const string &Y)
{
    int m = X.length();
    int k = Y.length();

    // Create a 2D vector to store the lengths of longest common subsequence
    vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));

    // Build the dp table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][k];
}

// Function to print the LCS
string printLCS(const string &X, const string &Y)
{
    int m = X.length();
    int k = Y.length();

    // Create a 2D vector to store the lengths of longest common subsequence
    vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));

    // Build the dp table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS from the dp table
    int i = m, j = k;
    string lcs;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return lcs;
}

int main()
{
    string X = "ABCBDAB";
    string Y = "BDCAB";

    cout << "Length of LCS is " << LCS(X, Y) << endl;
    cout << "LCS is " << printLCS(X, Y) << endl;

    return 0;
}