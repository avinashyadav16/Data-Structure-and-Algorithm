/**
*  @file: 131_Palindrome_Partitioning.cpp
*  @author: Avinash Yadav
*  @date: 10-06-2025
*  @link: https://leetcode.com/problems/palindrome-partitioning/description/
*  @brief: Given a string s, partition s such that every substring of the partition is a palindrome.
            Return all possible palindrome partitioning of s.
            Example 1:
                Input: s = "aab"
                Output: [["a","a","b"],["aa","b"]]

            Example 2:
                Input: s = "a"
                Output: [["a"]]

            Example 3:
                Input: s = "aaab"
                output = [["a","a","a","b"],["a","aa","b"],["aa","a","b"],["aaa","b"]]

            Example 4:
                Input: s = "abcaa"
                output = [["a","b","c","a","a"],["a","b","c","aa"]]

            Example 5:
                Input: s = "abbab"
                output = [["a","b","b","a","b"],["a","b","bab"],["a","bb","a","b"],["abba","b"]]

            Example 6:
                Input: s = "abaca"
                output = [["a","b","a","c","a"],["a","b","aca"],["aba","c","a"]]

            Example 7:
                Input: s = "aaa"
                output = [["a","a","a"],["a","aa"],["aa","a"],["aaa"]]
*/

#include <bits/stdc++.h>
using namespace std;

// Solution class to solve the palindrome partitioning problem
class Solution
{
public:
    // Function to check if the substring s[start...end] is a palindrome
    bool isPalindrome(string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
            {
                // Not a palindrome
                return false;
            }
        }

        // Is a palindrome
        return true;
    }

    // Recursive function to find all palindrome partitions
    // idx: current index in string s
    // ans: stores all possible partitions
    // path: current partition being built
    void findPartition(int idx, string &s, vector<vector<string>> &ans, vector<string> &path)
    {
        // If we have reached the end of the string,
        // add the current partition to the answer
        if (idx == s.size())
        {
            ans.push_back(path);
            return;
        }

        // Try all possible partitions starting from idx
        for (int i = idx; i < s.size(); i++)
        {
            // If the substring s[idx...i] is a palindrome
            if (isPalindrome(s, idx, i))
            {
                // Add substring to current path
                path.push_back(s.substr(idx, i - idx + 1));

                // Recurse for the remaining substring
                findPartition(i + 1, s, ans, path);

                // Backtrack and remove the last substring
                path.pop_back();
            }
        }
    }

    // Main function to return all palindrome partitions of string s
    vector<vector<string>> partition(string s)
    {
        // To store all partitions
        vector<vector<string>> ans;

        // To store current partition
        vector<string> path;

        // Start recursion from index 0
        findPartition(0, s, ans, path);

        return ans;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;

    vector<vector<string>> result = sol.partition(s);

    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";

        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
            {
                cout << ",";
            }
        }

        cout << "]";

        if (i < result.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]";

    return 0;
}