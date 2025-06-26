/**
*  @file: Kruskals_Algorithm.cpp
*  @author: Avinash Yadav
*  @date: 22-06-2025
*  @link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1
*  @brief: Given a weighted, undirected, and connected graph with V vertices and E edges,
            the task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph
            using Kruskal's Algorithm. The graph is represented as an edge list edges[][],
            where edges[i] = [u, v, w] denotes an undirected edge between u and v with weight w.

            Input: V = 3, E = 3, edges[][] = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
            Output: 4

            Input: V = 2, E = 1, edges = [[0, 1, 5]]
            Output: 5

*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> size;
    vector<int> parent;

    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulm_parent_u = findParent(u);
        int ulm_parent_v = findParent(v);

        if (ulm_parent_u == ulm_parent_v)
        {

            return;
        }

        if (size[ulm_parent_u] < size[ulm_parent_v])
        {
            parent[ulm_parent_u] = ulm_parent_v;
            size[ulm_parent_v] += size[ulm_parent_u];
        }
        else
        {
            parent[ulm_parent_v] = ulm_parent_u;
            size[ulm_parent_u] += size[ulm_parent_v];
        }
    }
};

class Solution
{
public:
    // Function to find the sum of weights of the edges in the Minimum Spanning Tree (MST)
    // using Kruskal's Algorithm.
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {
        // Sort all the edges in increasing order of their weights.
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });

        // Variable to store the total weight of the MST.
        int mstWT = 0;

        // Initialize Disjoint Set for union-find operations.
        DisjointSet ds(V);

        // Iterate through all sorted edges.
        for (auto &it : edges)
        {
            int u = it[0];  // First vertex of the edge.
            int v = it[1];  // Second vertex of the edge.
            int wt = it[2]; // Weight of the edge.

            // If u and v belong to different components, include this edge in MST.
            if (ds.findParent(u) != ds.findParent(v))
            {
                // Add the weight to the MST total.
                mstWT += wt;

                // Merge the two components.
                ds.unionBySize(u, v);
            }
            // If u and v are already connected, including this edge would form a cycle,
            // so we skip it.
        }

        // Return the total weight of the MST.
        return mstWT;
    }
};