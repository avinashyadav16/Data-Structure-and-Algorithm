/**
*  @file: 3_Longest_Substring_Without_Repeating_Characters.cpp
*  @author: Avinash Yadav
*  @date: 17-08-2025
*  @link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*  @brief: Given a string s, find the length of the longest substring without duplicate characters.
            Example 1:
                Input: s = "abcabcbb"
                Output: 3
                Explanation: The answer is "abc", with the length of 3.

            Example 2:
                Input: s = "bbbbb"
                Output: 1
                Explanation: The answer is "b", with the length of 1.

            Example 3:
                Input: s = "pwwkew"
                Output: 3
                Explanation: The answer is "wke", with the length of 3.
                Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

#include <bits/stdc++.h>
using namespace std;

// METHOD - 01
// TC: O(2N)
// SC: O(N)

class Solution1
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();

        // Set to store unique characters in the current window
        set<char> charSet;

        // Two pointers to define the sliding window
        int left = 0;
        int right = 0;

        // Variable to keep track of the maximum length found
        int maxLen = 0;

        // Iterate through the string using the right pointer
        while (right < n)
        {
            char currChar = s[right];

            // If current character is already in the set,
            // move left pointer to remove duplicates
            if (charSet.find(currChar) != charSet.end())
            {
                // Remove characters from the left
                // until currChar can be added
                while (charSet.find(currChar) != charSet.end())
                {
                    charSet.erase(s[left]);
                    left++;
                }
            }

            // Update the maximum length
            // if the current window is larger
            maxLen = max(maxLen, right - left + 1);

            // Add the current character to the set
            charSet.insert(currChar);

            // Move the right pointer forward
            right++;
        }

        // Return the maximum length found
        return maxLen;
    }
};

// METHOD - 02
// TC: O(N)
// SC: O(N)

class Solution2
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();

        // Hash map to store
        // the last index of each character seen so far
        unordered_map<int, int> charLastIdxMpp;

        // Two pointers to define the sliding window
        int left = 0;
        int right = 0;

        // Variable to keep track of the maximum length found
        int maxLen = 0;

        // Iterate through the string using the right pointer
        while (right < n)
        {
            char currChar = s[right];

            // If current character has been seen before and
            // its last index is within the current window,
            // move the left pointer to
            // one position after the last occurrence of currChar
            if (charLastIdxMpp.find(currChar) != charLastIdxMpp.end())
            {
                // Ensure left only moves forward
                left = max(left, charLastIdxMpp[currChar] + 1);
            }

            // Update the last index of the current character
            charLastIdxMpp[s[right]] = right;

            // Update the maximum length if current window is larger
            maxLen = max(maxLen, right - left + 1);

            // Move the right pointer forward
            right++;
        }

        // Return the maximum length found
        return maxLen;
    }
};

int main()
{
    Solution1 sol1;
    cout << sol1.lengthOfLongestSubstring("abcabcbb") << endl; // Output: 3
    cout << sol1.lengthOfLongestSubstring("bbbbb") << endl;    // Output: 1
    cout << sol1.lengthOfLongestSubstring("pwwkew") << endl;   // Output: 3

    Solution2 sol2;
    cout << sol2.lengthOfLongestSubstring("abcabcbb") << endl; // Output: 3
    cout << sol2.lengthOfLongestSubstring("bbbbb") << endl;    // Output: 1
    cout << sol2.lengthOfLongestSubstring("pwwkew") << endl;   // Output: 3

    return 0;
}