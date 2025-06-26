/**
 *  @file: Word_Search_II.cpp
 *  @brief: This file contains the implementation of the solution to the Word Search II problem.
 *          The problem is to find all words from a given list that exist in a 2D grid of characters.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
    // TrieNode structure
    struct TrieNode
    {
        char character;

        // Number of words ending at this TrieNode
        int wordEndCount;

        // The word ending at this TrieNode
        string word;

        // Pointers to child nodes
        TrieNode *child[26];
    };

    // Function to get a new TrieNode
    struct TrieNode *createTrieNode(char character)
    {
        TrieNode *newnode = new TrieNode;

        newnode->character = character;
        newnode->wordEndCount = 0;
        newnode->word = "";

        for (int i = 0; i < 26; i++)
        {
            newnode->child[i] = NULL;
        }

        return newnode;
    }

    // Root of the Trie
    TrieNode *root = createTrieNode('/');

    // Function to insert a word into the Trie
    void insertWord(string word)
    {
        TrieNode *currentNode = root;

        for (char c : word)
        {
            int index = c - 'a';
            if (currentNode->child[index] == NULL)
            {
                currentNode->child[index] = createTrieNode(c);
            }
            currentNode = currentNode->child[index];
        }
        currentNode->wordEndCount += 1;
        currentNode->word = word;
    }

    // Function to perform DFS and find words in the grid
    void dfsSearch(vector<vector<char>> &board, int i, int j, int rows, int cols, vector<string> &foundWords, TrieNode *currentNode)
    {
        // Base case: If the trie doesn't have the current char OR cell is visited
        int index = board[i][j] - 'a';

        if (board[i][j] == '$' || currentNode->child[index] == NULL)
        {
            return;
        }

        currentNode = currentNode->child[index];

        // If we have found a word, store it and mark it as found
        if (currentNode->wordEndCount > 0)
        {
            foundWords.push_back(currentNode->word);

            // To avoid duplicate insertions
            currentNode->wordEndCount -= 1;
        }

        // Store current char and mark current TrieNode visited
        char originalChar = board[i][j];
        board[i][j] = '$';

        // Explore all 4 possible directions
        if (i > 0) // TOP
        {
            dfsSearch(board, i - 1, j, rows, cols, foundWords, currentNode);
        }
        if (i < rows - 1) // DOWN
        {
            dfsSearch(board, i + 1, j, rows, cols, foundWords, currentNode);
        }
        if (j > 0) // LEFT
        {
            dfsSearch(board, i, j - 1, rows, cols, foundWords, currentNode);
        }
        if (j < cols - 1) // RIGHT
        {
            dfsSearch(board, i, j + 1, rows, cols, foundWords, currentNode);
        }

        // Mark current TrieNode as unvisited by restoring the value
        board[i][j] = originalChar;
    }

public:
    /**
     * @brief Finds all words from the given list that exist in the grid.
     *
     * @param board The 2D grid of characters.
     * @param words The list of words to be searched.
     * @return A vector containing all words found in the grid.
     */
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        // Total number of rows in the grid
        int rows = board.size();

        // Total number of columns in the grid
        int cols = board[0].size();

        // Insert all words in the Trie
        for (int i = 0; i < words.size(); i++)
        {
            insertWord(words[i]);
        }

        // Now search words
        vector<string> foundWords;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                dfsSearch(board, i, j, rows, cols, foundWords, root);
            }
        }
        return foundWords;
    }
};

int main()
{
    Solution sol;

    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}};

    vector<string> words = {"oath", "pea", "eat", "rain"};

    vector<string> result = sol.findWords(board, words);

    cout << "Words found in the board: ";
    for (const string &word : result)
    {
        cout << word << " ";
    }

    cout << endl;

    return 0;
}