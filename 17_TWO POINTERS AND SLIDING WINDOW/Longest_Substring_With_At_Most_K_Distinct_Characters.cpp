#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/**
 * Function to find the length of the longest substring with at most 'k' distinct characters.
 *
 * @param k   - The maximum number of distinct characters allowed in the substring.
 * @param str - The input string.
 * @return    - The length of the longest substring containing at most 'k' distinct characters.
 */
int longestSubstringWithKDistinctChars(int k, string &str)
{
    // Get the length of the string
    int size = str.size();

    // Two pointers for the sliding window
    int leftPtr = 0, rightPtr = 0;

    // Stores the maximum length of a valid substring
    int maxLen = 0;

    // HashMap to store frequency of characters in the current window
    unordered_map<char, int> mpp;

    // Traverse the string using the right pointer
    while (rightPtr < size)
    {
        // Include the current character in the window
        mpp[str[rightPtr]]++;

        // If the number of distinct characters exceeds 'k', shrink the window from the left
        if (mpp.size() > k)
        {
            // Reduce frequency of the leftmost character
            mpp[str[leftPtr]]--;

            // If frequency becomes 0, remove the character from the map
            if (mpp[str[leftPtr]] == 0)
            {
                mpp.erase(str[leftPtr]);
            }

            // Move left pointer ahead to shrink the window
            leftPtr++;
        }

        // Update the maximum length of a valid substring
        maxLen = max(maxLen, rightPtr - leftPtr + 1);

        // Expand the window by moving the right pointer
        rightPtr++;
    }

    return maxLen;
}

// Driver Code
int main()
{
    string inputString = "eceba";
    int k = 2;

    cout << "Longest substring length with at most " << k << " distinct characters: "
         << longestSubstringWithKDistinctChars(k, inputString) << endl;

    return 0;
}
