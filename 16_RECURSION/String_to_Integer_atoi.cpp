/**
 *  @file: String_to_Integer_(atoi).cpp
 *  @author: Avinash Yadav
 *  @date: 14-04-2025
 *  @link: https://leetcode.com/problems/string-to-integer-atoi/description
 *  @brief: Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
 */

#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int myAtoi(string s)
//     {
//         if (s.empty())
//         {
//             return 0;
//         }
//         int n = s.size();
//         int res = 0;
//         int currIdx = 0;
//         int sign = 1;
//         while (currIdx < n && s[currIdx] == ' ')
//         {
//             currIdx++;
//         }
//         if (currIdx == n)
//         {
//             return 0;
//         }
//         if (s[currIdx] == '+' || s[currIdx] == '-')
//         {
//             sign = (s[currIdx] == '-') ? -1 : 1;
//             currIdx++;
//         }
//         while (currIdx < n && isdigit(s[currIdx]))
//         {
//             int digit = s[currIdx] - '0';
//             if (res > (INT_MAX - digit) / 10)
//             {
//                 return sign == 1 ? INT_MAX : INT_MIN;
//             }
//             res = res * 10 + digit;
//             currIdx++;
//         }
//         return res * sign;
//     }
// };

class Solution
{
public:
    /**
     * Converts the string argument to an integer (32-bit signed integer).
     * Trims whitespace, manages sign, and processes characters until a non-digit is found,
     * or the number goes out of the 32-bit signed integer range.
     */
    int myAtoi(string s)
    {
        // Trim leading whitespace
        size_t firstNonSpace = s.find_first_not_of(" \t\n\r");
        if (firstNonSpace == string::npos)
        {
            // Return 0 if the string is just whitespace
            return 0;
        }
        // Trim leading whitespace
        s = s.substr(firstNonSpace);

        bool isPositive = true; // Flag indicating if the number is positive
        int index = 0;          // Index for iteration
        int result = 0;         // Variable to accumulate the parsed number

        // Check if there is a sign in the beginning
        if (s[index] == '+')
        {
            isPositive = true; // Positive number
            index++;
        }
        else if (s[index] == '-')
        {
            isPositive = false; // Negative number
            index++;
        }

        // Process each character in the string
        while (index < s.length())
        {
            char ch = s[index];

            // Break the loop if the character is not a digit
            if (!isdigit(ch))
            {
                break;
            }

            int digit = ch - '0';

            // Check for overflow: if the current result is already at the risk of overflow
            // with an additional digit, return the respective limit
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10))
            {
                return isPositive ? INT_MAX : INT_MIN;
            }

            // Update the result by adding the current digit
            result = result * 10 + digit;
            index++;
        }

        // Return the final result, considering the sign
        return isPositive ? result : -result;
    }
};

int main()
{
    Solution sol;

    cout << "Converted integer: " << sol.myAtoi("4193 with words") << endl; // Output: 4193
    cout << "Converted integer: " << sol.myAtoi("words and 987") << endl;   // Output: 0
    cout << "Converted integer: " << sol.myAtoi("-91283472332") << endl;    // Output: -2147483648
    cout << "Converted integer: " << sol.myAtoi("2147483648") << endl;      // Output: 2147483647
    cout << "Converted integer: " << sol.myAtoi("   +0 123") << endl;       // Output: 0
    cout << "Converted integer: " << sol.myAtoi("   -0 123") << endl;       // Output: 0
    cout << "Converted integer: " << sol.myAtoi("   +42") << endl;          // Output: 42
    cout << "Converted integer: " << sol.myAtoi("   -42") << endl;          // Output: -42

    return 0;
}
