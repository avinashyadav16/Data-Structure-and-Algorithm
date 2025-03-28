/**
 *  @file: Minimum_Window_Substring.cpp
 *  @author: Avinash Yadav
 *  @brief: Finds the minimum window substring in 's' that contains all characters of 't' in any order.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @brief Finds the minimum window in 's' that contains all characters of 't'.
     *
     * @param s The input string in which we are searching.
     * @param t The target string whose characters must be present in the window.
     * @return The smallest substring of 's' containing all characters of 't'.
     */
    string minWindow(string s, string t)
    {
        // Tracks how many characters of 't' are matched in the current window
        int cnt = 0;

        // Stores the length of the smallest valid window
        int minLen = INT_MAX;

        // Stores the start index of the minimum window
        int startIndex = -1;

        int left = 0;
        int right = 0;

        // Frequency map to store counts of characters in 't'
        vector<int> hashMap(256, 0);

        // Populate the frequency map with characters of 't'
        for (char ch : t)
        {
            hashMap[ch]++;
        }

        // Expand the window by moving the right pointer
        while (right < s.size())
        {
            // If the character at 'right' is needed and has +ve freq,
            // increase matched count
            if (hashMap[s[right]] > 0)
            {
                cnt++;
            }

            // Decrease the frequency of the current character
            hashMap[s[right]]--;

            // If all characters of 't' are matched,
            // try to shrink the window
            while (cnt == t.size())
            {
                // Update the minimum window size
                // if the current window is smaller
                if ((right - left + 1) < minLen)
                {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                // Remove the leftmost character from the window
                hashMap[s[left]]++;

                // If the removed character was needed for 't',
                // reduce the matched count
                if (hashMap[s[left]] > 0)
                {
                    cnt--;
                }

                // Move the left pointer to shrink the window
                left++;
            }

            // Expand the window by moving the right pointer
            right++;
        }

        // If no valid window was found, return an empty string
        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};

int main()
{
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "Minimum window substring: " << solution.minWindow(s, t) << endl;

    return 0;
}
