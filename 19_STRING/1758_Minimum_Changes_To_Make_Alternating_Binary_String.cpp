/**
 * @file: 1758_Minimum_Changes_To_Make_Alternating_Binary_String.cpp
 * @author: Avinash Yadav
 * @date: 05-03-2026
 * @link: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string
 * @brief: You are given a string `s` consisting only of the characters '0' and '1'.
            In one operation, you can change any '0' to '1' or vice versa.

            The string is called alternating if no two adjacent characters are equal.
            For example, the string "010" is alternating, while the string "0100" is not.

            Return the minimum number of operations needed to make s alternating.

            Example 1:
                Input: s = "0100"
                Output: 1
                Explanation: If you change the last character to '1', `s` will be "0101", which is alternating.

            Example 2:
                Input: s = "10"
                Output: 0
                Explanation: `s` is already alternating.

            Example 3:
                Input: s = "1111"
                Output: 2
                Explanation: You need two operations to reach "0101" or "1010".

            Constraints:
                1 <= s.length <= 10^4
                s[i] is either '0' or '1'.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int mismatchStartWith0 = 0; // Expected pattern: 010101...
        int mismatchStartWith1 = 0; // Expected pattern: 101010...

        for (int i = 0; i < (int)s.size(); i++)
        {
            char expectedForPattern0 = (i % 2 == 0) ? '0' : '1';
            char expectedForPattern1 = (i % 2 == 0) ? '1' : '0';

            if (s[i] != expectedForPattern0)
            {
                mismatchStartWith0++;
            }

            if (s[i] != expectedForPattern1)
            {
                mismatchStartWith1++;
            }
        }

        return min(mismatchStartWith0, mismatchStartWith1);
    }
};

int main()
{
    string s1 = "0100";
    string s2 = "10";
    string s3 = "1111";

    Solution sol;

    cout << sol.minOperations(s1) << endl; // Output: 1
    cout << sol.minOperations(s2) << endl; // Output: 0
    cout << sol.minOperations(s3) << endl; // Output: 2

    return 0;
}