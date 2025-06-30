/**
 *  @file: LCS_DistinctLCS.cpp
 *  @author: Avinash Yadav
 *  @date: 06-06-2025
 *  @link: https://www.codechef.com/problems/J2?tab=statement
 *  @brief: Given two strings S and T, the LCS problem is the find the longest sequence that is a subsequence of both S and T.
            Given two strings S and T, how many distinct LCS of S and T are there?
            Write a program to help Johnny solve this problem.
            Since the result may be very large, you only need to print the remainder of the result when dividing by 23102009.
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 23102009;

/**
 * @brief Recursively finds the length of the Longest Common Subsequence (LCS) using memoization.
 *
 * The LCS problem is to find the longest sequence that appears as a subsequence in both strings.
 * This function uses memoization to avoid recomputation and fills a DP table with LCS lengths.
 *
 * @param i Index in the first string
 * @param j Index in the second string
 * @param s First input string
 * @param t Second input string
 * @param dp Memoization table to store LCS lengths
 * @return Length of LCS ending at s[i] and t[j]
 */
int findLCS(int i, int j, const string &s, const string &t, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
    {
        // Base case: If either string is empty, LCS is 0
        return 0;
    }

    if (dp[i][j] != -1)
    {
        // Return already computed value
        return dp[i][j];
    }

    if (s[i] == t[j])
    {
        // If characters match, include it in LCS
        return dp[i][j] = 1 + findLCS(i - 1, j - 1, s, t, dp);
    }
    else
    {
        // Otherwise, take the maximum by skipping one character from either string
        return dp[i][j] = max(findLCS(i - 1, j, s, t, dp), findLCS(i, j - 1, s, t, dp));
    }
}

/**
 * @brief Counts the number of distinct LCS sequences of a given length using memoization and inclusion-exclusion.
 *
 * The function counts the number of unique LCS sequences of a given length by recursively exploring all possibilities.
 * It uses inclusion-exclusion to avoid double-counting subsequences that can be formed by skipping characters from both strings.
 *
 * @param i Index in first string
 * @param j Index in second string
 * @param remainingLen Remaining length of LCS to be formed
 * @param s First input string
 * @param t Second input string
 * @param n Length of first string
 * @param m Length of second string
 * @param lcsDP Table with precomputed LCS lengths
 * @param memoCnt Memoization table for counting LCS
 * @return Number of distinct LCS of length `remainingLen` ending at s[0..i] and t[0..j]
 */
int countDistinctLCS(int i, int j, int remainingLen, const string &s, const string &t, int n, int m,
                     vector<vector<int>> &lcsDP, vector<vector<int>> &memoCnt)
{
    if (remainingLen == 0)
    {
        // Found a valid LCS of required length
        return 1;
    }
    if (i < 0 || j < 0)
    {
        // Out of bounds, no valid LCS
        return 0;
    }

    if (memoCnt[i][j] != -1)
    {
        // Return already computed value
        return memoCnt[i][j];
    }

    int ways = 0;

    if (s[i] == t[j])
    {
        // If characters match and can be part of LCS, include them
        if (lcsDP[i][j] == remainingLen)
        {
            ways = countDistinctLCS(i - 1, j - 1, remainingLen - 1, s, t, n, m, lcsDP, memoCnt);
        }
    }
    else
    {
        // Try skipping character from s
        if (i > 0 && lcsDP[i - 1][j] == remainingLen)
        {
            ways = (ways + countDistinctLCS(i - 1, j, remainingLen, s, t, n, m, lcsDP, memoCnt)) % MOD;
        }
        // Try skipping character from t
        if (j > 0 && lcsDP[i][j - 1] == remainingLen)
        {
            ways = (ways + countDistinctLCS(i, j - 1, remainingLen, s, t, n, m, lcsDP, memoCnt)) % MOD;
        }
        // Inclusion-exclusion: subtract cases where both characters are skipped to avoid double-counting
        if (i > 0 && j > 0 && lcsDP[i - 1][j] == remainingLen && lcsDP[i][j - 1] == remainingLen && lcsDP[i - 1][j - 1] == remainingLen)
        {
            ways = (ways - countDistinctLCS(i - 1, j - 1, remainingLen, s, t, n, m, lcsDP, memoCnt) + MOD) % MOD;
        }
    }

    return memoCnt[i][j] = ways;
}

int main()
{
    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        string s, t;
        cin >> s >> t;

        int n = s.size();
        int m = t.size();

        // Step 1: Compute LCS length using DP
        vector<vector<int>> lcsDP(n, vector<int>(m, -1));
        findLCS(n - 1, m - 1, s, t, lcsDP);
        int lcsLength = lcsDP[n - 1][m - 1];

        // Step 2: Count number of distinct LCS of length `lcsLength`
        vector<vector<int>> memoCnt(n, vector<int>(m, -1));
        int totalWays = countDistinctLCS(n - 1, m - 1, lcsLength, s, t, n, m, lcsDP, memoCnt);

        // Output: LCS length and number of distinct LCS modulo MOD
        cout << lcsLength << " " << totalWays << endl;
    }

    return 0;
}
