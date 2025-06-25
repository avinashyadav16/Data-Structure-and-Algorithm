/**
*  @file: Alien_Dictionary.cpp
*  @author: Avinash Yadav
*  @date: 21-06-2025
*  @link: https://www.geeksforgeeks.org/problems/alien-dictionary/1
*  @brief: A new alien language uses the English alphabet,
            but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary,
            where the words are claimed to be sorted lexicographically according to the language’s rules.

            Your task is to determine the correct order of letters in this alien language based on the given words.
            If the order is valid, return a string containing the unique letters in lexicographically increasing order
            as per the new language's rules. If there are multiple valid orders, return any one of them.

            However, if the given arrangement of words is inconsistent with any possible letter ordering,
            return an empty string ("").

            A string a is lexicographically smaller than a string b if, at the first position where they differ,
            the character in a appears earlier in the alien language than the corresponding character in b.
            If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

            Note: Your implementation will be tested using a driver code.
            It will print true if your returned order correctly follows the alien language’s lexicographic rules;
            otherwise, it will print false.

            Examples:

            Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
            Output: true
            Explanation: A possible corrct order of letters in the alien dictionary is "bdac".
            The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
            The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
            The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
            The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
            So, 'b' → 'd' → 'a' → 'c' is a valid ordering.

            Input: words[] = ["caa", "aaa", "aab"]
            Output: true
            Explanation: A possible corrct order of letters in the alien dictionary is "cab".
            The pair "caa" and "aaa" suggests 'c' appears before 'a'.
            The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary.
            So, 'c' → 'a' → 'b' is a valid ordering.

            Input: words[] = ["ab", "cd", "ef", "ad"]
            Output: ""
            Explanation: No valid ordering of letters is possible.
            The pair "ab" and "ef" suggests "a" appears before "e".
            The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to perform topological sort using Kahn's algorithm
    vector<int> topoSort(int nodes, vector<vector<int>> &adjList)
    {
        vector<int> indegree(nodes, 0);

        // Calculate indegree for each node
        for (int i = 0; i < nodes; i++)
        {
            for (auto &adj : adjList[i])
            {
                indegree[adj]++;
            }
        }

        queue<int> q;

        // Push all nodes with indegree 0 into the queue
        for (int i = 0; i < nodes; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;

        // Standard BFS for topological sorting
        while (!q.empty())
        {
            int currNode = q.front();
            q.pop();

            topo.push_back(currNode);

            // Decrease indegree of adjacent nodes
            for (auto &adj : adjList[currNode])
            {
                indegree[adj]--;

                // If indegree becomes 0, add to queue
                if (indegree[adj] == 0)
                {
                    q.push(adj);
                }
            }
        }

        return topo;
    }

    string findOrder(vector<string> &words)
    {
        int n = words.size();

        // Number of unique characters
        int K = 0;

        // Track which characters are present
        vector<bool> present(26, false);

        for (const auto &word : words)
        {
            for (char c : word)
            {
                present[c - 'a'] = true;
            }
        }

        // Count unique characters
        for (int i = 0; i < 26; ++i)
        {
            if (present[i])
            {
                K++;
            }
        }

        // Adjacency list for the graph
        vector<vector<int>> adjList(26);

        // Build the graph by comparing adjacent words
        for (int i = 0; i < n - 1; i++)
        {
            string word1 = words[i];
            string word2 = words[i + 1];

            int len = min(word1.size(), word2.size());

            // Edge case:
            // If word1 is a prefix of word2 but longer, invalid order
            if (word1.substr(0, len) == word2.substr(0, len) &&
                word1.size() > word2.size())
            {
                return "";
            }

            // Find the first differing character and create an edge
            for (int ptr = 0; ptr < len; ptr++)
            {
                if (word1[ptr] != word2[ptr])
                {
                    adjList[word1[ptr] - 'a'].push_back(word2[ptr] - 'a');
                    break;
                }
            }
        }

        // Perform topological sort
        vector<int> topo = topoSort(26, adjList);

        string ans = "";
        // Build the answer string using only present characters
        for (auto &it : topo)
        {
            if (present[it])
            {
                ans += char(it + 'a');
            }
        }

        // If not all present letters are in topo,
        // there is a cycle (invalid order)
        if (ans.size() != K)
        {
            return "";
        }

        return ans;
    }
};