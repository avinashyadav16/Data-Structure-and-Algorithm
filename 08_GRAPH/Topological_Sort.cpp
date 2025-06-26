/**
*  @file: Topological_Sort.cpp
*  @author: Avinash Yadav
*  @date: 21-06-2025
*  @link: https://www.geeksforgeeks.org/problems/topological-sort/1
*  @brief: Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][],
            where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

            Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v,
            vertex u comes before v in the ordering.
            Note: As there are multiple Topological orders possible,
            you may return any of them. If your returned Topological sort is correct then the output will be true else false.

            Examples:
                Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]
                Output: true
                Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
                [3, 2, 1, 0]
                [1, 2, 3, 0]
                [2, 3, 1, 0]

                Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5,2]]
                Output: true
                Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
                [4, 5, 0, 1, 2, 3]
                [5, 2, 4, 0, 1, 3]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Perform DFS traversal and fill the stack with topological order
    void dfsTraversal(int node, vector<vector<int>> &edges,
                      vector<bool> &vis, stack<int> &st)
    {
        // Mark the current node as visited
        vis[node] = true;

        // Visit all the adjacent nodes
        for (auto &adj : edges[node])
        {
            if (!vis[adj])
            {
                // Recursive DFS call
                dfsTraversal(adj, edges, vis, st);
            }
        }

        // Push the node to stack after visiting all its neighbors
        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // Adjacency list representation of the graph
        vector<vector<int>> adj(V);

        for (auto &edge : edges)
        {
            // Build the adjacency list
            adj[edge[0]].push_back(edge[1]);
        }

        // Visited array to keep track of visited nodes
        vector<bool> vis(V, false);

        // Stack to store the topological order
        stack<int> st;

        // Perform DFS from every unvisited node
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsTraversal(i, adj, vis, st);
            }
        }

        // Vector to store the final topological order
        vector<int> ans;

        while (!st.empty())
        {
            // Pop elements from stack to get the order
            ans.push_back(st.top());

            st.pop();
        }

        // Return the topological sort
        return ans;
    }
};