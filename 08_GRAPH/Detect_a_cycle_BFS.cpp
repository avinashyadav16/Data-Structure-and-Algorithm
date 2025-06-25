/**
*  @file: Detect_a_cycle_BFS.cpp
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

// Solution class to detect cycle in an undirected graph using BFS
class Solution
{
public:
    // Function to detect cycle starting from 'src' using BFS
    bool detectCycleBFS(int src, vector<vector<int>> &edges, vector<bool> &vis)
    {
        // Mark the source node as visited
        vis[src] = true;

        // Queue stores pairs of (current_node, parent_node)
        queue<pair<int, int>> qp;

        // Start BFS from src, with parent as -1
        qp.push({src, -1});

        while (!qp.empty())
        {
            int node = qp.front().first;
            int parent = qp.front().second;
            qp.pop();

            // Traverse all adjacent nodes
            for (auto adj : edges[node])
            {
                if (!vis[adj])
                {
                    // Mark adjacent node as visited
                    vis[adj] = true;

                    // Push adjacent node with current node as parent
                    qp.push({adj, node});
                }
                // If adjacent node is visited and not parent, cycle exists
                else if (adj != parent)
                {
                    return true;
                }
            }
        }

        // No cycle found starting from src
        return false;
    }

    // Main function to check if the graph contains a cycle
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // Adjacency list
        vector<vector<int>> adj(V);

        // Convert edge list to adjacency list
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            // Since the graph is undirected
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Visited array
        vector<bool> vis(V, false);

        // Check for cycle in each connected component
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detectCycleBFS(i, adj, vis))
                {
                    // Cycle found
                    return true;
                }
            }
        }

        // No cycle in any component
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