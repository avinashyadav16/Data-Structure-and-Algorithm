/**
 * @file: 1888_Minimum_Number_of_Flips_to_Make_the_Binary_String_Alternating.cpp
 * @author: Avinash Yadav
 * @date: 07-03-2026
 * @link: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description
 * @brief: You are given a binary string `s`. You are allowed to perform two types of operations on the string in any sequence:
                - Type-1: Remove the character at the start of the string `s` and append it to the end of the string.
                - Type-2: Pick any character in `s` and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
            Return the minimum number of type-2 operations you need to perform such that `s` becomes alternating.
            The string is called alternating if no two adjacent characters are equal.

            For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

            Example 1:
                Input: s = "111000"
                Output: 2
                Explanation: Use the first operation two times to make s = "100011".
                Then, use the second operation on the third and sixth elements to make s = "101010".

            Example 2:
                Input: s = "010"
                Output: 0
                Explanation: The string is already alternating.

            Example 3:
                Input: s = "1110"
                Output: 1
                Explanation: Use the second operation on the second element to make s = "1010".

            Constraints:
                1 <= s.length <= 10^5
                s[i] is either '0' or '1'.

 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlips(string s)
    {
        int stringLength = s.length();

        // diff1 for pattern "0101..."
        int mismatchesWithZeroStartPattern = 0;

        // diff2 for pattern "1010..."
        int mismatchesWithOneStartPattern = 0;

        int minimumFlips = INT_MAX;

        // Simulate a doubled string of length 2*N
        for (int index = 0; index < 2 * stringLength; index++)
        {
            // Use i % n to avoid allocating memory for a new string s + s
            char currChar = s[index % stringLength];

            // The expected characters for both patterns at the current index i
            char expectedCharacterForZeroStartPattern = (index % 2 == 0) ? '0' : '1';
            char expectedCharacterForOneStartPattern = (index % 2 == 0) ? '1' : '0';

            // Increment differences if the current character doesn't match
            if (currChar != expectedCharacterForZeroStartPattern)
            {
                mismatchesWithZeroStartPattern++;
            }
            if (currChar != expectedCharacterForOneStartPattern)
            {
                mismatchesWithOneStartPattern++;
            }

            // Remove the old element from the sliding window when it exceeds length n
            if (index >= stringLength)
            {
                int windowStartIndex = index - stringLength;
                char characterLeavingWindow = s[windowStartIndex % stringLength];
                char expectedCharacterLeavingForZeroStartPattern = (windowStartIndex % 2 == 0) ? '0' : '1';
                char expectedCharacterLeavingForOneStartPattern = (windowStartIndex % 2 == 0) ? '1' : '0';

                if (characterLeavingWindow != expectedCharacterLeavingForZeroStartPattern)
                {
                    mismatchesWithZeroStartPattern--;
                }
                if (characterLeavingWindow != expectedCharacterLeavingForOneStartPattern)
                {
                    mismatchesWithOneStartPattern--;
                }
            }

            // Update the minimum flips once the window reaches size n
            if (index >= stringLength - 1)
            {
                minimumFlips = min({minimumFlips, mismatchesWithZeroStartPattern, mismatchesWithOneStartPattern});
            }
        }

        return minimumFlips;
    }
};

int main()
{
    string firstInput = "111000";
    string secondInput = "010";
    string thirdInput = "1110";

    Solution solution;

    cout << solution.minFlips(firstInput) << endl;  // OUTPUT: 2
    cout << solution.minFlips(secondInput) << endl; // OUTPUT: 0
    cout << solution.minFlips(thirdInput) << endl;  // OUTPUT: 1

    return 0;
}