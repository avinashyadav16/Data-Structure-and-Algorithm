/**
*  @file: Rat_in_a_Maze_Problem_I.cpp
*  @author: Avinash Yadav
*  @date: 10-06-2025
*  @link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*  @brief: Consider a rat placed at position (0, 0) in an n x n square matrix mat[][].
            The rat's goal is to reach the destination at position (n-1, n-1).
            The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).
            The matrix contains only two possible values:
                0: A blocked cell through which the rat cannot travel.
                1: A free cell that the rat can pass through.

            Your task is to find all possible paths the rat can take to reach the destination,
            starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path.
            Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
            If no path exists, return an empty list.

            Note: Return the final result vector in lexicographically smallest order.

            Examples:
                Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
                Output: ["DDRDRR", "DRDDRR"]
                Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths
                             - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
*/

#include <bits/stdc++.h>
using namespace std;

// METHOD 01:
class Solution
{
public:
    // Function to recursively find all paths from (i, j) to (n-1, n-1)
    void findPath(int i, int j, int n, string path, vector<vector<int>> &maze, vector<string> &ans, vector<vector<int>> &vis)
    {
        // If destination is reached,
        // add the current path to the answer list
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(path);
            return;
        }

        // Move Down ('D')
        if (i + 1 < n && !vis[i + 1][j] && maze[i + 1][j] == 1)
        {
            // Mark current cell as visited
            vis[i][j] = 1;

            findPath(i + 1, j, n, path + 'D', maze, ans, vis);

            // Backtrack: unmark current cell
            vis[i][j] = 0;
        }

        // Move Left ('L')
        if (j - 1 >= 0 && !vis[i][j - 1] && maze[i][j - 1] == 1)
        {
            vis[i][j] = 1;
            findPath(i, j - 1, n, path + 'L', maze, ans, vis);
            vis[i][j] = 0;
        }

        // Move Right ('R')
        if (j + 1 < n && !vis[i][j + 1] && maze[i][j + 1] == 1)
        {
            vis[i][j] = 1;
            findPath(i, j + 1, n, path + 'R', maze, ans, vis);
            vis[i][j] = 0;
        }

        // Move Up ('U')
        if (i - 1 >= 0 && !vis[i - 1][j] && maze[i - 1][j] == 1)
        {
            vis[i][j] = 1;
            findPath(i - 1, j, n, path + 'U', maze, ans, vis);
            vis[i][j] = 0;
        }
    }

    // Main function to find all possible paths in the maze
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        // Size of the maze
        int n = maze.size();

        // To store all valid paths
        vector<string> ans;

        // Visited matrix to keep track of visited cells in current path
        vector<vector<int>> vis(n, vector<int>(n, 0));

        // Start the search only if the starting cell is not blocked
        if (maze[0][0] == 1)
        {
            findPath(0, 0, n, "", maze, ans, vis);
        }

        // Return all found paths
        return ans;
    }
};

// METHOD 02:

class Solution
{
public:
    vector<int> dirI = {1, 0, 0, -1};
    vector<int> dirJ = {0, -1, +1, 0};

    void findPath(int i, int j, int n, string path,
                  vector<vector<int>> &maze,
                  vector<string> &ans,
                  vector<vector<int>> &vis)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(path);
            return;
        }

        string DIR = "DLRU";

        for (int idx = 0; idx < 4; idx++)
        {
            int newi = i + dirI[idx];
            int newj = j + dirJ[idx];

            if (newi >= 0 && newj >= 0 &&
                newi < n && newj < n &&
                !vis[newi][newj] &&
                maze[newi][newj] == 1)
            {
                vis[newi][newj] = 1;
                findPath(newi, newj, n, path + DIR[idx], maze, ans, vis);
                vis[newi][newj] = 0;
            }
        }
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {

        int n = maze.size();

        vector<string> ans;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (maze[0][0] == 1)
        {
            findPath(0, 0, n, "", maze, ans, vis);
        }

        return ans;
    }
};