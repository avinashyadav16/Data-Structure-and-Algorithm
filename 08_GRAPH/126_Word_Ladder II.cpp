/**
*  @file: 126_Word_Ladder II.cpp
*  @author: Avinash Yadav
*  @date: 20-06-2025
*  @link: https://leetcode.com/problems/word-ladder-ii/description/
*  @brief: A transformation sequence from word beginWord to word endWord
            using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
            Every adjacent pair of words differs by a single letter.
            Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
            sk == endWord
            Given two words, beginWord and endWord, and a dictionary wordList,
            return all the shortest transformation sequences from beginWord to endWord, o
            r an empty list if no such sequence exists.
            Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

            Example 1:
                Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
                Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
                Explanation: There are 2 shortest transformation sequences:
                "hit" -> "hot" -> "dot" -> "dog" -> "cog"
                "hit" -> "hot" -> "lot" -> "log" -> "cog"

            Example 2:
                Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
                Output: []
                Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string> &wordList)
    {
        // Insert all words from wordList into an unordered_set
        // for O(1) lookup and deletion.
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Queue to perform BFS,
        // each element is a sequence (vector) of words
        // representing the path so far.
        queue<vector<string>> q;

        // Start BFS with the beginWord as the first sequence.
        q.push({beginWord});

        // Vector to keep track of words used at the current BFS level.
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);

        // Variable to track the current BFS level (sequence length).
        int level = 0;

        // Vector to store all shortest transformation sequences found.
        vector<vector<string>> ans;

        // Perform BFS until all possible sequences are explored.
        while (!q.empty())
        {
            // Get the current sequence from the queue.
            vector<string> vec = q.front();
            
            q.pop();

            // If we have moved to a new level (longer sequence),
            // remove all words used in the previous level from the set.
            if (vec.size() > level)
            {
                level++;

                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }

                // Clear usedOnLevel for the next level.
                usedOnLevel.clear();
            }

            // Get the last word in the current sequence.
            string word = vec.back();

            // If the last word matches endWord,
            // check if this is the shortest sequence found so far.
            if (word == endWord)
            {
                // If this is the first sequence found,
                // add it to the answer.
                if (ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                // If this sequence is of the same length as the shortest found,
                // add it as well.
                else if (ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }

                // If the sequence is longer than the shortest,
                // do not add (since BFS guarantees shortest first).
            }

            // Try changing each character of the current word
            // to every letter from 'a' to 'z'.
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    // If the new word exists in the set,
                    // it is a valid transformation.
                    if (st.count(word) > 0)
                    {
                        // Add the new word to the current sequence and
                        // push the new sequence to the queue.
                        vec.push_back(word);
                        q.push(vec);

                        // Mark this word as used on this level.
                        usedOnLevel.push_back(word);

                        // Remove the new word to backtrack for the next iteration.
                        vec.pop_back();
                    }
                }

                // Restore the original character before moving to the next position.
                word[i] = original;
            }
        }

        // Return all shortest transformation sequences found.
        return ans;
    }
};