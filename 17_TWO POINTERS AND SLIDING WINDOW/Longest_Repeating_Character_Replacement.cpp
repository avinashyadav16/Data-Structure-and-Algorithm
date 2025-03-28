/**
 *  @file: Longest_Repeating_Character_Replacement.cpp
 *  @author: Avinash Yadav
 *  @brief:
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int left = 0;
        int right = 0;

        // Stores the maximum valid substring length
        int maxLen = 0;

        // Stores the maximum frequency of any character in the current window
        int maxFreq = 0;

        // Frequency map for characters 'A' to 'Z'
        vector<int> hashMap(26, 0);

        while (right < n)
        {
            // Increment the frequency of the current character
            hashMap[s[right] - 'A']++;

            // Update the maximum frequency of any character in the current window
            maxFreq = max(maxFreq, hashMap[s[right] - 'A']);

            // Check if the number of characters to be replaced exceeds the allowed limit (k)
            if ((right - left + 1) - maxFreq > k)
            {
                // If exceeded, shrink the window from the left
                hashMap[s[left] - 'A']--;
                left += 1;
            }

            // Update the maximum valid substring length found so far
            maxLen = max(maxLen, (right - left + 1));

            // Expand the window by moving the right pointer
            right += 1;
        }

        return maxLen;
    }
};

int main()
{

    return 0;
}