/**
*  @file: Detect_a_cycle_DFS.cpp
*  @author: Avinash Yadav
*  @date: 18-06-2025
*  @brief: Given an undirected graph with V vertices labeled from 0 to V-1. The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. Determine if the graph contains any cycles.
            Note: The graph does not contain any self-edges (edges where a vertex is connected to itself).

            Examples:
                Input: V = 6, adj= [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]]
                Output: True
                Explanation: The graph contains a cycle: 0 ->1 -> 2 -> 5 -> 4 -> 1.

                Input: V = 4, adj= [[1, 2], [0], [0, 3], [2]]
                Output: False
                Explanation: The graph does not contain any cycles.
*/

#include <bits/stdc++.h>
using namespace std;

// Functionality: Detects a cycle in an undirected graph using DFS.
// The graph is represented as an adjacency list.
// - detectCycleDFS: Function to perform DFS and detect cycles.
// - isCycle: Prepares the adjacency list and initiates DFS for all components.
class Solution
{
public:
    // Function to perform DFS and detect a cycle in an undirected graph
    bool detectCycleDFS(int node, int parent,
                        vector<vector<int>> &edges, vector<bool> &vis)
    {
        // Mark the current node as visited
        vis[node] = true;

        // Traverse all adjacent nodes
        for (auto adj : edges[node])
        {
            // If the adjacent node is not visited
            if (!vis[adj])
            {
                // Recursively visit the adjacent node
                if (detectCycleDFS(adj, node, edges, vis))
                {
                    // Cycle found in the DFS subtree
                    return true;
                }
            }
            else if (adj != parent)
            {
                // If the adjacent node is visited and is not the parent,
                // a cycle exists
                return true;
            }
        }

        // No cycle found from this node
        return false;
    }

    // Check if the undirected graph contains a cycle
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // Adjacency list for the graph
        vector<vector<int>> adj(V);

        // Build the adjacency list from the edge list
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            // Add v to u's adjacency list
            adj[u].push_back(v);

            // Add u to v's adjacency list (undirected)
            adj[v].push_back(u);
        }

        // Track visited nodes
        vector<bool> vis(V, false);

        // Check each component of the graph
        for (int i = 0; i < V; i++)
        {
            // If the node is not visited
            if (!vis[i])
            {
                // Start DFS from this node
                if (detectCycleDFS(i, -1, adj, vis))
                {
                    // Cycle detected
                    return true;
                }
            }
        }

        // No cycle found in any component
        return false;
    }
};

int main()
{
    int V1 = 6;
    vector<vector<int>> edges1 = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}}; // Output: True

    int V2 = 4;
    vector<vector<int>> edges2 = {{1, 2}, {0}, {0, 3}, {2}}; // Output: False

    int V3 = 4;
    vector<vector<int>> edges3 = {{1, 2}, {2, 3}}; // Output: False

    Solution sol1;

    cout << boolalpha << sol1.isCycle(V1, edges1) << endl;
    cout << boolalpha << sol1.isCycle(V2, edges2) << endl;
    cout << boolalpha << sol1.isCycle(V3, edges3) << endl;

    return 0;
}