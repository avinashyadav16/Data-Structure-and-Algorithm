/**
*  @file: 29.Divide_Two_Integers.cpp
*  @author: Avinash Yadav
*  @date: 02-06-2025
*  @link: https://leetcode.com/problems/divide-two-integers/description/
*  @brief: Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
            The integer division should truncate toward zero, which means losing its fractional part.
            For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

            Return the totalQuotient after dividing dividend by divisor.

            Note:
            Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the totalQuotient is strictly greater than 231 - 1, then return 231 - 1, and if the totalQuotient is strictly less than -231, then return -231.

            Example 1:
                Input: dividend = 10, divisor = 3
                Output: 3
                Explanation: 10/3 = 3.33333.. which is truncated to 3.

            Example 2:
                Input: dividend = 7, divisor = -3
                Output: -2
                Explanation: 7/-3 = -2.33333.. which is truncated to -2.


            Constraints:
                -2^31 <= dividend, divisor <= (2^31) - 1
                divisor != 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // Edge case: Overflow when dividing INT_MIN by -1
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine the sign of the result using XOR
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Convert both dividend and divisor to long long and take absolute values
        long long absDividend = labs(dividend);
        long long absDivisor = labs(divisor);

        long long totalQuotient = 0;

        // Subtract the largest shifted divisor possible from the dividend
        while (absDividend >= absDivisor)
        {
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            // Double tempDivisor and multiple until it's greater than absDividend
            while (absDividend >= (tempDivisor << 1))
            {
                tempDivisor <<= 1; // tempDivisor = tempDivisor * 2
                multiple <<= 1;    // multiple = multiple * 2
            }

            absDividend -= tempDivisor;
            totalQuotient += multiple;
        }

        // Applying sign
        totalQuotient = isNegative ? -totalQuotient : totalQuotient;

        // Clamp result within 32-bit signed integer range
        return static_cast<int>(totalQuotient);
    }
};
