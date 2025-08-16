/**
*  @file: 402_Remove_K_Digits.cpp
*  @author: Avinash Yadav
*  @date: 15-08-2025
*  @link: https://leetcode.com/problems/remove-k-digits/description/
*  @brief: Given string num representing a non-negative integer num, and an integer k,
             return the smallest possible integer after removing k digits from num.

            Example 1:
                Input: num = "1432219", k = 3
                Output: "1219"
                Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

            Example 2:
                Input: num = "10200", k = 1
                Output: "200"
                Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

            Example 3:
                Input: num = "10", k = 2
                Output: "0"
                Explanation: Remove all the digits from the number and it is left with nothing which is 0.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();

        stack<char> st;

        // Iterate through each digit in num
        for (int i = 0; i < n; i++)
        {
            // Remove digits from the stack
            // if they are greater than the current digit
            // and we still have k digits to remove
            while (!st.empty() &&
                   k > 0 &&
                   ((st.top() - '0') > (num[i] - '0')))
            {
                st.pop();
                k--;
            }

            // Push the current digit onto the stack
            st.push(num[i]);
        }

        // If there are still digits to remove,
        // pop from the stack
        while (k > 0)
        {
            st.pop();
            k--;
        }

        // If the stack is empty, return "0"
        if (st.empty())
        {
            return "0";
        }

        string res = "";
        // Build the result string from the stack
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        // Remove leading zeros from the result
        while (res.size() != 0 && res.back() == '0')
        {
            res.pop_back();
        }

        // Reverse the result to get the correct order
        reverse(res.begin(), res.end());

        // If the result is empty after removing zeros,
        // return "0"
        if (res.empty())
        {
            return "0";
        }

        return res;
    }
};
