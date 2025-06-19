/**
*  @file: 542_01_Matrix.cpp
*  @author: Avinash Yadav
*  @date: 19-06-2025
*  @link: https://leetcode.com/problems/01-matrix/description/
*  @brief: Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
            The distance between two cells sharing a common edge is 1.

            Example 1:
                Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
                Output: [[0,0,0],[0,1,0],[0,0,0]]

            Example 2:
                Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
                Output: [[0,0,0],[0,1,0],[1,2,1]]
*/

#include <bits/stdc++.h>
using namespace std;

// Solution class to solve the 01 Matrix problem
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        // Distance matrix to store the result
        vector<vector<int>> dis(m, vector<int>(n, 0));

        // Visited matrix to keep track of processed cells
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Queue for BFS: stores ((row, col), distance)
        queue<pair<pair<int, int>, int>> qp;

        // Initialize queue with all 0-cells and
        // mark them visited
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    qp.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        // BFS to find shortest distance to 0 for each cell
        while (!qp.empty())
        {
            int row = qp.front().first.first;
            int col = qp.front().first.second;
            int step = qp.front().second;

            qp.pop();

            // Set the distance for current cell
            dis[row][col] = step;

            // Directions: up, right, down, left
            int dr[] = {-1, 0, +1, 0};
            int dc[] = {0, +1, 0, -1};

            // Explore all 4 neighbors
            for (int i = 0; i < 4; i++)
            {
                int newR = row + dr[i];
                int newC = col + dc[i];

                // If neighbor is within bounds and not visited
                if (newR >= 0 && newR < m &&
                    newC >= 0 && newC < n &&
                    !vis[newR][newC])
                {
                    qp.push({{newR, newC}, step + 1});
                    vis[newR][newC] = true;
                }
            }
        }

        return dis;
    }
};

int main()
{

    vector<vector<int>> mat1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}; // Output: [[0,0,0],[0,1,0],[0,0,0]]
    vector<vector<int>> mat2 = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}}; // Output: [[0,0,0],[0,1,0],[1,2,1]]

    auto printImage = [](const vector<vector<int>> &img)
    {
        for (const auto &row : img)
        {
            for (int val : row)
                cout << val << " ";
            cout << endl;
        }

        cout << endl;
    };

    cout << "OUTPUT IS: " << endl;
    Solution sol1;
    printImage(sol1.updateMatrix(mat1));
    printImage(sol1.updateMatrix(mat2));

    return 0;
}