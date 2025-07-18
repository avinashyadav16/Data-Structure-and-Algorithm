/**
 *  @file: Palindromic_Substrings
 *  @author: Avinash Yadav
 *  @brief: https://leetcode.com/problems/palindromic-substrings/description/
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// METHOD - 01
class Solution1
{
public:
    bool check(string &s, int i, int j)
    {
        if (i > j)
        {
            return true;
        }

        if (s[i] == s[j])
        {
            return check(s, i + 1, j - 1);
        }

        return false;
    }

    int countSubstrings(string s)
    {
        int n = s.size();

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (check(s, i, j))
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

// METHOD - 02
class Solution2
{
public:
    int t[1001][1001];
    bool check(string &s, int i, int j)
    {
        if (i > j)
        {
            return true;
        }

        if (t[i][j] != -1)
        {
            return t[i][j];
        }

        if (s[i] == s[j])
        {
            return t[i][j] = check(s, i + 1, j - 1);
        }

        return t[i][j] = 0;
    }

    int countSubstrings(string s)
    {
        int n = s.size();

        int cnt = 0;
        memset(t, -1, sizeof(t));
        // t[i][j] = -1 means not calculated yet
        // t[i][j] = 0 means not a palindrome => False
        // t[i][j] = 1 means a palindrome => True

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (check(s, i, j))
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

// METHOD - 03
class Solution3
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();

        int cnt = 0;

        vector<vector<bool>> t(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;

                if (i == j)
                {
                    t[i][j] = true;
                }
                else if (i + 1 == j)
                {
                    t[i][j] = (s[i] == s[j]);
                }
                else
                {
                    t[i][j] = (s[i] == s[j] && t[i + 1][j - 1]);
                }

                if (t[i][j])
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

// METHOD - 04
class Solution4
{
public:
    int cnt;

    void extendPalindrome(string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            cnt++;
            left--;
            right++;
        }
    }

    int countSubstrings(string s)
    {
        int n = s.size();

        cnt = 0;

        for (int i = 0; i < n; i++)
        {
            extendPalindrome(s, i, i);     // odd length
            extendPalindrome(s, i, i + 1); // even length
        }

        return cnt;
    }
};

int main()
{

    return 0;
}