/**
*  @file: M_Coloring_Problem.cpp
*  @author: Avinash Yadav
*  @date: 10-06-2025
*  @link: https://takeuforward.org/plus/dsa/problems/m-coloring-problem
*  @link: https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
*  @brief: Given an integer M and an undirected graph with N vertices and E edges.
            The goal is to determine whether the graph can be coloured with a maximum of M colors
            so that no two of its adjacent vertices have the same colour applied to them.
            In this context, colouring a graph refers to giving each vertex a different colour.
            If the colouring of vertices is possible then return true, otherwise return false.

            Examples:
                Input : N = 4 , M = 3 , E = 5 , Edges = [ (0, 1) , (1, 2) , (2, 3) , (3, 0) , (0, 2) ]
                Output : true

            Explanation: Consider the three colors to be red, green, blue.
                        We can color the vertex 0 with red, vertex 1 with blue, vertex 2 with green, vertex 3 with blue.
                        In this way we can color graph using 3 colors at most.
*/

#include <bits/stdc++.h>
using namespace std;

// Solution class to solve the M-Coloring Problem
class Solution
{
public:
    // Helper function to check if it's safe to color the current node with color 'col'
    bool isSafe(int node, vector<int> &color, int col, int n, vector<vector<int>> &edges)
    {
        // Check all adjacent nodes
        for (int i = 0; i < n; i++)
        {
            // If there is an edge and the adjacent node has the same color, it's not safe
            if ((edges[node][i] == 1 || edges[i][node] == 1) && color[i] == col)
            {
                return false;
            }
        }
        // Safe to color
        return true;
    }

    // Recursive function to try coloring the graph using backtracking
    bool isPossible(int node, vector<int> &color, int m, int n, vector<vector<int>> &edges)
    {
        // If all nodes are colored, return true
        if (node == n)
        {
            return true;
        }

        // Try all colors for the current node
        for (int col = 1; col <= m; col++)
        {
            // Check if it's safe to color with 'col'
            if (isSafe(node, color, col, n, edges))
            {
                color[node] = col; // Assign color

                // Recur for the next node
                if (isPossible(node + 1, color, m, n, edges))
                {
                    return true;
                }

                // Backtrack if not possible
                color[node] = 0;
            }
        }

        // If no color can be assigned, return false
        return false;
    }

    // Main function to check if the graph can be colored with at most m colors
    bool graphColoring(vector<vector<int>> &edges, int m, int n)
    {
        // Initialize all colors as 0 (no color)
        vector<int> color(n, 0);

        // Start coloring from the first node
        if (isPossible(0, color, m, n, edges))
        {
            return true;
        }

        return false;
    }
};

int main()
{

    Solution sol;

    // TC: 01
    int n = 4;
    int m = 3;
    vector<pair<int, int>> edgeList = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2}};

    // TC: 02
    // int n = 3;
    // int m = 2;
    // vector<pair<int, int>> edgeList = {{0, 1}, {1, 2}, {0, 2}};

    vector<vector<int>> edges(n, vector<int>(n, 0));

    for (auto &[u, v] : edgeList)
    {
        edges[u][v] = 1;
        edges[v][u] = 1;
    }

    cout << boolalpha << sol.graphColoring(edges, m, n) << endl;

    return 0;
}