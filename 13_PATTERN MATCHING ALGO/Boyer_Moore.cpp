/**
*  @file: Boyer_Moore.cpp
*  @author: Avinash Yadav
*  @brief: Boyer-Moore Algorithm
           The Boyer-Moore algorithm is an efficient string-searching algorithm that improves the time complexity of searching for a substring within a string.
           It uses information gathered during the preprocessing phase to skip sections of the text, reducing the number of comparisons needed.

           Explanation
           - Preprocessing:
                ~ The algorithm preprocesses the pattern to create two tables:
                    ~ Bad Character Table: This table is used to skip sections of the text when a mismatch is found.
                    ~ Good Suffix Table: This table is used to skip sections of the text based on the suffixes of the pattern.

           - Searching:
                ~ The pattern is aligned with the beginning of the text.
                ~ The algorithm compares the pattern from right to left.
                ~ If a mismatch is found, it uses the bad character and good suffix tables to determine how far to shift the pattern.
*  @date: 19-05-2024
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define NO_OF_CHARS 256

// Function to create the bad character table
void badCharHeuristic(const string &pattern, int size, vector<int> &badChar)
{
    for (int i = 0; i < NO_OF_CHARS; i++)
    {
        // Initialize all occurrences as -1
        badChar[i] = -1;
    }

    for (int i = 0; i < size; i++)
    {
        // Fill the actual value of the last occurrence of a character
        badChar[(int)pattern[i]] = i;
    }
}

// Boyer Moore algorithm
vector<int> BoyerMoore(const string &text, const string &pattern)
{
    int m = pattern.size();
    int n = text.size();

    vector<int> badChar(NO_OF_CHARS);
    badCharHeuristic(pattern, m, badChar);

    vector<int> result;

    // s is the shift of the pattern with respect to text
    int s = 0;

    while (s <= (n - m))
    {
        int j = m - 1;

        // Keep reducing index j of pattern while characters of pattern and text are matching at this shift s
        while (j >= 0 && pattern[j] == text[s + j])
        {
            j--;
        }

        // If the pattern is present at current shift, then index j will become -1 after the above loop
        if (j < 0)
        {
            result.push_back(s);
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        }
        else
        {
            s += max(1, j - badChar[text[s + j]]);
        }
    }

    return result;
}

int main()
{
    string text = "ABAAABCD";
    string pattern = "ABC";

    vector<int> result = BoyerMoore(text, pattern);

    cout << "Pattern found at positions: ";
    for (int pos : result)
    {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}