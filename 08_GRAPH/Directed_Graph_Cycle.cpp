/**
*  @file: Directed_Graph_Cycle.cpp
*  @author: Avinash Yadav
*  @date: 19-06-2025
*  @link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*  @brief: Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges,
            check whether it contains any cycle or not.
            The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.

            Examples:
                Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 0], [2, 3]]
                Output: true
                Explanation: The diagram clearly shows a cycle 0 → 2 → 0

                Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]
                Output: false
                Explanation: no cycle in the graph
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * Helper function to perform DFS and check for cycles in the graph.
     * @param node: The current node being visited.
     * @param adj: The adjacency list representing the graph.
     * @param vis: Boolean vector to keep track of visited nodes.
     * @param pathVis: Boolean vector to keep track of nodes in the
     *                  current DFS path (recursion stack).
     * @return: True if a cycle is detected, otherwise false.
     */
    bool dfsCheck(int node, vector<vector<int>> &adj,
                  vector<bool> &vis, vector<bool> &pathVis)
    {
        // Mark the current node as visited globally.
        vis[node] = true;

        // Mark the current node as part of the current DFS path.
        pathVis[node] = true;

        // Traverse all adjacent nodes of the current node.
        for (auto &neighbour : adj[node])
        {
            // If the adjacent node has not been visited
            //, recursively visit it.
            if (!vis[neighbour])
            {
                // If a cycle is detected in the recursion,
                // return true.
                if (dfsCheck(neighbour, adj, vis, pathVis))
                {
                    return true;
                }
            }
            // If the adjacent node is already in the current DFS path,
            // a cycle is found.
            else if (pathVis[neighbour])
            {
                return true;
            }
        }

        // Remove the node from the current DFS path before backtracking.
        pathVis[node] = false;

        // No cycle found from this node.
        return false;
    }

    /**
     * Main function to check if the directed graph contains a cycle.
     * @param V: Number of vertices in the graph.
     * @param edges: List of directed edges,
     *               where each edge is represented as [u, v].
     * @return: True if the graph contains a cycle, otherwise false.
     */
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // Initialize visited and path visited arrays for all nodes.

        // Tracks if a node has been visited in any DFS traversal.
        vector<bool> vis(V, false);

        // Tracks if a node is in the current DFS path (recursion stack).
        vector<bool> pathVis(V, false);

        // Build the adjacency list from the edge list.
        vector<vector<int>> adj(V);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }

        // Check for cycles starting from each unvisited node.
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                // If a cycle is detected starting from node i,
                // return true.
                if (dfsCheck(i, adj, vis, pathVis))
                {
                    return true;
                }
            }
        }

        // No cycle detected in any component of the graph.
        return false;
    }
};