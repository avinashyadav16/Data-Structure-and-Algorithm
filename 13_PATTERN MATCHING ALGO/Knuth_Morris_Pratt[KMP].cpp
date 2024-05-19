/**
 *  @file: Knuth_Morris_Pratt[KMP].cpp
 *  @author: Avinash Yadav
 *  @brief: The Knuth-Morris-Pratt (KMP) algorithm is an efficient string matching algorithm
            that avoids unnecessary comparisons by using information from previous matches.
            It preprocesses the pattern to create a partial match table (also known as the "prefix function")
            that indicates the longest proper prefix which is also a suffix.

            Explanation
            - Preprocessing:
                Create the partial match table (prefix function) which helps in determining the next positions to match in the pattern after a mismatch.

            - Searching:
                Use the partial match table to skip characters in the text, avoiding re-evaluations of previously matched characters.
 *  @date: 19-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to preprocess the pattern and create the partial match table (prefix function)
void computeLPSArray(const string &pattern, int M, vector<int> &lps)
{
    // Length of the previous longest prefix suffix
    int length = 0;

    int i = 1;

    // lps[0] is always 0
    lps[0] = 0;

    // Loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP algorithm for pattern searching
vector<int> KMPSearch(const string &text, const string &pattern)
{
    int N = text.size();
    int M = pattern.size();

    vector<int> lps(M);
    vector<int> result;

    // Preprocess the pattern to create the LPS array
    computeLPSArray(pattern, M, lps);

    // index for text[]
    int i = 0;

    // index for pattern[]
    int j = 0;

     while (i < N)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == M)
        {
            // Pattern found at index i - j
            result.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < N && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return result;
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    vector<int> result = KMPSearch(text, pattern);

    cout << "Pattern found at positions: ";
    for (int pos : result)
    {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}