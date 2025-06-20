/**
*  @file: 127_Word_Ladder.cpp
*  @author: Avinash Yadav
*  @date: 19-06-2025
*  @link: https://leetcode.com/problems/word-ladder/description/
*  @brief: A transformation sequence from word beginWord to word endWord
            using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

            Every adjacent pair of words differs by a single letter.
            Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
            sk == endWord
            Given two words, beginWord and endWord, and a dictionary wordList,
            return the number of words in the shortest transformation sequence from beginWord to endWord,
            or 0 if no such sequence exists.

            Example 1:
                Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
                Output: 5
                Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

            Example 2:
                Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
                Output: 0
                Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList)
    {
        // Insert all words from wordList
        // into a set for O(1) lookup and removal
        set<string> st(wordList.begin(), wordList.end());

        // Queue for BFS: stores pairs of
        // (current word, current transformation step count)
        queue<pair<string, int>> q;

        // Start BFS from beginWord with step count 1
        q.push({beginWord, 1});

        while (!q.empty())
        {
            // Current word
            string word = q.front().first;

            // Number of steps taken to reach this word
            int step = q.front().second;

            q.pop();

            // If the current word matches endWord,
            // we've found the shortest transformation
            if (word == endWord)
            {
                return step;
            }

            // Try changing every character in the current word
            // to every possible lowercase letter
            for (int i = 0; i < word.size(); i++)
            {
                // Store the original character
                char originalChar = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    // Change the i-th character to ch
                    word[i] = ch;

                    // If the new word exists in the set
                    // (i.e., is in wordList and not yet visited)
                    if (st.find(word) != st.end())
                    {
                        // Add the new word to the queue
                        // with incremented step count
                        q.push({word, step + 1});

                        // Remove the word from the set
                        // to prevent revisiting
                        st.erase(word);
                    }
                }

                // Restore the original character
                // for the next iteration
                word[i] = originalChar;
            }
        }

        // If endWord is not reachable, return 0
        return 0;
    }
};