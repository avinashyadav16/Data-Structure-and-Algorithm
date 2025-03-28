/**
 *  @file: Longest_Substring_Without_Repeating_Characters.cpp
 *  @author: Avinash Yadav
 *  @brief: This program finds the length of the longest substring
 *          without repeating characters using the sliding window approach.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // Length of the input string
        int size = s.size();

        // Left boundary of the sliding window
        int leftPtr = 0;

        // Right boundary of the sliding window
        int rightPtr = 0;

        // Stores the maximum length of a unique substring
        int maxLen = 0;

        // Stores the last seen index of each character
        vector<int> hashArr(256, -1);

        while (rightPtr < size)
        {
            // If character was seen before and its index is within the current window
            if (hashArr[s[rightPtr]] != -1)
            {
                if (hashArr[s[rightPtr]] >= leftPtr)
                {
                    // Move left pointer to avoid repetition
                    leftPtr = hashArr[s[rightPtr]] + 1;
                }
            }

            // Calculate current window length and update maxLen
            int currLen = rightPtr - leftPtr + 1;
            maxLen = max(maxLen, currLen);

            // Update last seen index of the current character
            hashArr[s[rightPtr]] = rightPtr;

            // Expand the window
            rightPtr++;
        }

        // Return the maximum length of a unique substring
        return maxLen;
    }
};

int main()
{
    Solution sol;
    string input = "abcabcbb";
    cout << "Length of longest substring without repeating characters: "
         << sol.lengthOfLongestSubstring(input) << endl;

    return 0;
}
