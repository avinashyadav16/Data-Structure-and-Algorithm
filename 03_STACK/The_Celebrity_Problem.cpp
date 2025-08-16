/**
*  @file: The_Celebrity_Problem.cpp
*  @author: Avinash Yadav
*  @date: 15-08-2025
*  @link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
*  @brief: A celebrity is a person who is known to all but does not know anyone at a party.
            A party is being organized by some people.
            A square matrix mat[][] (n*n) is used to represent people at the party such that
            if an element of row i and column j is set to 1 it means ith person knows jth person.
            You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

            Note: Follow 0-based indexing.

            Examples:

                Input: mat[][] = [[1, 1, 0], [0, 1, 0], [0, 1, 1]]
                Output: 1
                Explanation: 0th and 2nd person both know 1st person. Therefore, 1 is the celebrity person.

                Input: mat[][] = [[1, 1], [1, 1]]
                Output: -1
                Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.

                Input: mat[][] = [[1]]
                Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    // Function to find the celebrity in the party
    // mat: n x n matrix
    // where mat[i][j] == 1 means person i knows person j
    int celebrity(vector<vector<int>> &mat)
    {
        // Number of people at the party
        int n = mat.size();

        // Should be equal to n (square matrix)
        int m = mat[0].size();

        // knowMe[i]: number of people who know person i
        vector<int> knowMe(n, 0);

        // iKnow[i]: number of people person i knows
        vector<int> iKnow(n, 0);

        // Count for each person
        // how many people know them and how many they know
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    // Person i knows person j

                    // Increment count for person j being known
                    knowMe[j]++;

                    // Increment count for person i knowing someone
                    iKnow[i]++;
                }
            }
        }

        // A celebrity is known by everyone else (n-1 people)
        // and knows no one
        for (int i = 0; i < n; i++)
        {
            // condition when in problem statement mat[i][i] == 0
            // if (knowMe[i] == n - 1 && iKnow[i] == 0)
            // {
            //     return i;
            // }

            // condition when in problem statement mat[i][i] == 1
            if (knowMe[i] == n && iKnow[i] == 1)
            {
                // Found the celebrity
                return i;
            }
        }

        // No celebrity found
        return -1;
    }
};

class Solution2
{
public:
    // Find the celebrity in the party using two-pointer approach
    // mat: n x n matrix
    // where mat[i][j] == 1 means person i knows person j
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();

        // Initialize two pointers:
        // top at 0, down at n-1
        int top = 0;
        int down = n - 1;

        // Find the potential celebrity
        // by eliminating non-celebrities
        while (top < down)
        {
            // If top knows down, top cannot be celebrity,
            // move top forward
            if (mat[top][down] == 1)
            {
                top++;
            }
            // If down knows top, down cannot be celebrity,
            // move down backward
            else if (mat[down][top] == 1)
            {
                down--;
            }
            // If neither knows each other,
            // eliminate both and move pointers
            else
            {
                top++;
                down--;
            }
        }

        // If pointers crossed, no celebrity found
        if (top > down)
        {
            return -1;
        }

        // Verify if the candidate at 'top'
        // is actually a celebrity
        for (int i = 0; i < n; i++)
        {
            if (i == top)
            {
                // Skip self-check
                continue;
            }

            // Celebrity should not know anyone,
            // and everyone should know celebrity
            else if (mat[top][i] == 0 && mat[i][top] == 1)
            {
                continue;
            }
            else
            {
                // If any condition fails, not a celebrity
                return -1;
            }
        }

        // Return the celebrity index
        return top;
    }
};