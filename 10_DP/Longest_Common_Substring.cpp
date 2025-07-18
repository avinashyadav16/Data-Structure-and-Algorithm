/**
*  @file: Longest_Common_Substring.cpp
*  @author: Avinash Yadav
*  @date: 01-07-2025
*  @link: https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
*  @brief: You are given two strings s1 and s2.
            Your task is to find the length of the longest common substring among the given strings.

            Examples:
                Input: s1 = "ABCDGH", s2 = "ACDGHR"
                Output: 4
                Explanation: The longest common substring is "CDGH" with a length of 4.

                Input: s1 = "abc", s2 = "acb"
                Output: 1
                Explanation: The longest common substrings are "a", "b", "c" all having length 1.

                Input: s1 = "YZ", s2 = "yz"
                Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        // Length of first string
        int n = s1.size();

        // Length of second string
        int m = s2.size();

        // Create a 2D DP table initialized to 0.
        // dp[i][j] will store the length of the lC substring
        // ending at s1[i-1] and s2[j-1].
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // To keep track of the maximum length found
        int ans = 0; 

        // Iterate through both strings
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // If characters match, extend the previous substring
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    
                    // Update the answer if needed
                    ans = max(ans, dp[i][j]); 
                }
                else
                {
                    // No common substring ends here
                    dp[i][j] = 0; 
                }
            }
        }

        // Return the length of the longest common substring
        return ans; 
    }
};
