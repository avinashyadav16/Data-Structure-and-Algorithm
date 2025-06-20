/**
*  @file: 785_Is_Graph_Bipartite.cpp
*  @author: Avinash Yadav
*  @date: 19-06-2025
*  @link: https://leetcode.com/problems/is-graph-bipartite/description/
*  @brief: There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1.
            You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to.
            More formally, for each v in graph[u], there is an undirected edge between node u and node v.
            The graph has the following properties:

            There are no self-edges (graph[u] does not contain u).
            There are no parallel edges (graph[u] does not contain duplicate values).
            If v is in graph[u], then u is in graph[v] (the graph is undirected).
            The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
            A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

            Return true if and only if it is bipartite.

            Example 1:
                Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
                Output: false
                Explanation: There is no way to partition the nodes into two independent sets
                such that every edge connects a node in one and a node in the other.

            Example 2:
                Input: graph = [[1,3],[0,2],[1,3],[0,2]]
                Output: true
                Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check
    // if the component containing 'node' is bipartite using BFS
    bool check(int node, vector<vector<int>> &graph, vector<int> &color)
    {
        queue<int> q;
        q.push(node);

        // Assign the first color (0) to the starting node
        color[node] = 0;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            // Traverse all adjacent nodes (neighbors)
            for (auto &neighbour : graph[curr])
            {
                if (color[neighbour] == -1)
                {
                    // If the neighbor has not been colored,
                    // assign the opposite color
                    color[neighbour] = 1 - color[curr];
                    q.push(neighbour);
                }
                else if (color[neighbour] == color[curr])
                {
                    // If the neighbor has the same color as the current node,
                    // the graph is not bipartite
                    return false;
                }
            }
        }

        // All nodes in this component can be colored with 2 colors,
        // so it's bipartite
        return true;
    }

    // Main function to check if the entire graph is bipartite
    bool isBipartite(vector<vector<int>> &graph)
    {
        int m = graph.size();

        // Initialize all nodes as uncolored (-1)
        vector<int> color(m, -1);

        // Check each component of the graph
        // (in case the graph is disconnected)
        for (int i = 0; i < m; i++)
        {
            if (color[i] == -1)
            {
                // If the node is uncolored, check its component
                if (!check(i, graph, color))
                {
                    // If any component is not bipartite, return false
                    return false;
                }
            }
        }

        // All components are bipartite
        return true;
    }
};