/**
*  @file: 20_Valid_Parentheses.cpp
*  @author: Avinash Yadav
*  @date: 09-08-2025
*  @link: https://leetcode.com/problems/valid-parentheses/description/
*  @brief: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
            An input string is valid if:
                Open brackets must be closed by the same type of brackets.
                Open brackets must be closed in the correct order.
                Every close bracket has a corresponding open bracket of the same type.

            Example 1:
                Input: s = "()"
                Output: true

            Example 2:
                Input: s = "()[]{}"
                Output: true

            Example 3:
                Input: s = "(]"
                Output: false

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();

        // Stack to keep track of opening brackets
        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            // If current character is an opening bracket,
            // push it onto the stack
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else // If it's a closing bracket
            {
                // If stack is empty,
                // there is no matching opening bracket
                if (st.empty())
                {
                    return false;
                }

                // Get the top element from the stack
                char topEle = st.top();

                // Remove the top element
                st.pop();

                // Check if the current closing bracket
                // matches the last opening bracket
                if (!((s[i] == ')' && topEle == '(') ||
                      (s[i] == '}' && topEle == '{') ||
                      (s[i] == ']' && topEle == '[')))
                {
                    // Mismatched brackets
                    return false;
                }
            }
        }

        // If stack is empty,
        // all brackets were matched correctly
        return st.empty();
    }
};

int main()
{
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";

    Solution sol;

    cout << boolalpha << sol.isValid(s1) << endl;
    cout << boolalpha << sol.isValid(s2) << endl;
    cout << boolalpha << sol.isValid(s3) << endl;

    return 0;
}