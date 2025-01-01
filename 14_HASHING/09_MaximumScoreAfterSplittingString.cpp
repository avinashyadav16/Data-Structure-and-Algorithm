/**
*  @file: 09_MaximumScoreAfterSplittingString.cpp
*  @author: Avinash Yadav
*  @link: https://leetcode.com/problems/maximum-score-after-splitting-a-string?envType=daily-question&envId=2025-01-01
*  @brief: 1422. Maximum Score After Splitting a String
Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).
The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

Example 1:
Input: s = "011101"
Output: 5

Explanation:
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5
left = "01" and right = "1101", score = 1 + 3 = 4
left = "011" and right = "101", score = 1 + 2 = 3
left = "0111" and right = "01", score = 1 + 1 = 2
left = "01110" and right = "1", score = 2 + 1 = 3

*  @date: 01-01-2025
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    int maxScore(string s)
    {
        int oneCnt = 0;
        int zeroCnt = 0;
        int maxScr = INT_MIN;

        for (auto &st : s)
        {
            if (st == '1')
            {
                oneCnt++;
            }
        }

        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '1')
            {
                oneCnt--;
            }
            else
            {
                zeroCnt++;
            }

            maxScr = max(maxScr, (oneCnt + zeroCnt));
        }

        return maxScr;
    }
};

int main()
{

    return 0;
}