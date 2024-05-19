/**
 *  @file: Brute_Force.cpp
 *  @author: Avinash Yadav
 *  @brief: Brute force approach for pattern searching in text

            Algorithm:
            - The naive string matching algorithm slides the pattern one by one over the text and checks for a match.
            - For each position in the text, it checks if the substring of the text starting from that position matches the pattern.
            - If all characters of the pattern match the corresponding characters in the text, a match is found.

            Time Complexity:
            - The worst-case time complexity is O((n−m+1)⋅m),
                where n is the length of the text and m is the length of the pattern.
            - In the worst case, for each position in the text, the algorithm compares m characters of the pattern.
 *  @date: 19-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to perform pattern search
vector<int> naivePatternSearch(const string &text, const string &pattern)
{
    vector<int> result;     // To store positions of pattern matches
    int n = text.size();    // Length of the text
    int m = pattern.size(); // Length of the pattern

    // Loop through the text to slide the pattern one by one
    for (int i = 0; i <= n - m; i++)
    {
        int j;

        // Check for pattern match at current position
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                // Mismatch found, break out of the loop
                break;
            }
        }

        // If pattern is found, add the current position to result
        if (j == m)
        {
            result.push_back(i);
        }
    }

    // Return positions of all matches
    return result;
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    // Call the pattern search function
    vector<int> result = naivePatternSearch(text, pattern);

    // Print the positions of matches
    cout << "Pattern found at positions: ";
    for (int pos : result)
    {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}