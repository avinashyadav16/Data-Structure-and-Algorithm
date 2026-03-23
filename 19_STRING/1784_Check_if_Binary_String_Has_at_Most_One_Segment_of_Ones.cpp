/**
 * @file: 1784_Check_if_Binary_String_Has_at_Most_One_Segment_of_Ones.cpp
 * @author: Avinash Yadav
 * @date: 06-03-2026
 * @link: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description
 * @brief: Given a binary string s ​​​​​without leading zeros, return true​​​ if `s` contains at most one contiguous segment of ones.
           Otherwise, return false.

            Example 1:
                Input: s = "1001"
                Output: false
                Explanation: The ones do not form a contiguous segment.

            Example 2:
                Input: s = "110"
                Output: true

            Constraints:
                1 <= s.length <= 100
                s[i]​​​​ is either '0' or '1'.
                s[0] is '1'.

            Hint 1
                It's guaranteed to have at least one segment
            Hint 2
                The string size is small so you can count all segments of ones with no that have no adjacent ones.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        bool seenZero = false;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                seenZero = true;
            }
            else if (s[i] == '1' && seenZero)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    string s1 = "1001";
    string s2 = "110";
    string s3 = "1";
    string s4 = "10";

    Solution sol;

    cout << boolalpha << sol.checkOnesSegment(s1) << endl; // output: false
    cout << boolalpha << sol.checkOnesSegment(s2) << endl; // output: true
    cout << boolalpha << sol.checkOnesSegment(s3) << endl; // output: true
    cout << boolalpha << sol.checkOnesSegment(s4) << endl; // output: true

    return 0;
}