/**
*  @file: Shortest_Path_in_Undirected_Graph.cpp
*  @author: Avinash Yadav
*  @date: 21-06-2025
*  @link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
*  @brief: You are given an adjacency list, adj of Undirected Graph having unit weight of the edges,
            find the shortest path from src to all the vertex and if it is unreachable to reach any vertex,
            then return -1 for that vertex.

            Examples :

            Input: adj[][] = [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]], src=0
            Output: [0, 1, 2, 1, 2, 3, 3, 4, 4]

            Input: adj[][]= [[3], [3], [], [0, 1]], src=3
            Output: [1, 1, -1, 0]

            Input: adj[][]= [[], [], [], [4], [3], [], []], src=1
            Output: [-1, 0, -1, -1, -1, -1, -1]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        // Number of vertices in the graph
        int V = adj.size();

        // Initialize distance vector with a large value
        // (representing infinity)
        vector<int> dis(V, 1e9);

        // Distance to source is 0
        dis[src] = 0;

        queue<int> q; // Queue for BFS traversal
        q.push(src);  // Start BFS from the source node

        // Standard BFS loop
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // Traverse all adjacent nodes
            // (neighbors) of the current node
            for (auto &neighbor : adj[node])
            {
                // If a shorter path to neighbor is found
                if (dis[node] + 1 < dis[neighbor])
                {
                    // Update distance
                    dis[neighbor] = 1 + dis[node];

                    // Enqueue neighbor for further exploration
                    q.push(neighbor);
                }
            }
        }

        // Prepare the answer vector:
        // if a node is unreachable, set distance as -1
        vector<int> ans(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (dis[i] != 1e9)
            {
                // Set the computed shortest distance
                ans[i] = dis[i];
            }

            // Else, ans[i] remains -1 (unreachable)
        }

        // Return the shortest distances from src to all vertices
        return ans;
    }
};