/**
 *  @file: Number_of_Substrings_Containing_All_Three_Characters.cpp
 *  @author: Avinash Yadav
 *  @brief:
 */

#include <bits/stdc++.h>
using namespace std;

// METHOD 1
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> mpp;
            mpp['a'] = 0;
            mpp['b'] = 0;
            mpp['c'] = 0;
            for (int j = i; j < n; j++)
            {
                mpp[s[j] - 'a'] = 1;

                if (mpp[0] + mpp[1] + mpp[2] == 3)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// METHOD 2
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> mpp;
            mpp['a'] = 0;
            mpp['b'] = 0;
            mpp['c'] = 0;
            for (int j = i; j < n; j++)
            {
                mpp[s[j] - 'a'] = 1;

                if (mpp[0] + mpp[1] + mpp[2] == 3)
                {
                    cnt += (n - j);
                    break;
                }
            }
        }
        return cnt;
    }
};

// METHOD - 03

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();

        // Stores the total count of valid substrings
        int cnt = 0;

        // Map to store the last seen index of characters 'a', 'b', and 'c'
        unordered_map<int, int> lastSeenIndex;

        // Initialize 'a' index to -1 (not seen)
        lastSeenIndex[0] = -1;

        // Initialize 'b' index to -1 (not seen)
        lastSeenIndex[1] = -1;

        // Initialize 'c' index to -1 (not seen)
        lastSeenIndex[2] = -1;

        // Iterate through the string
        for (int i = 0; i < n; i++)
        {
            // Update the last seen index of the current character
            // ('a' -> 0, 'b' -> 1, 'c' -> 2)
            lastSeenIndex[s[i] - 'a'] = i;

            // Check if all three characters have been seen at least once
            if (lastSeenIndex[0] != -1 && lastSeenIndex[1] != -1 && lastSeenIndex[2] != -1)
            {
                // Find the earliest index among 'a', 'b', and 'c'
                int minIndex = min(lastSeenIndex[0], min(lastSeenIndex[1], lastSeenIndex[2]));

                // Add (minIndex + 1) substrings to the count
                cnt += (minIndex + 1);
            }

            // This will also work, no need to check for the above 'if' condition
            // int minIndex = min(lastSeenIndex[0], min(lastSeenIndex[1], lastSeenIndex[2]));
            // cnt += (minIndex + 1);
        }

        return cnt;
    }
};