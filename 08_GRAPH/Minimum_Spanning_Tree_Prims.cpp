/**
*  @file: Minimum_Spanning_Tree_Prims.cpp
*  @author: Avinash Yadav
*  @date: 22-06-2025
*  @link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
*  @brief: Given a weighted, undirected, and connected graph with V vertices and E edges,
            your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph.
            The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers.
            Each vector represents an edge, with the first integer denoting the endpoint of the edge and
            the second integer denoting the weight of the edge.

                Input:
                3 3
                0 1 5
                1 2 3
                0 2 1
                Output: 4

                Input:
                2 1
                0 1 5
                Output: 5

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the sum of weights of the Minimum Spanning Tree (MST)
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Min-heap to pick the edge with the smallest weight at each step
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        // Visited array to keep track of nodes included in MST
        vector<bool> vis(V, false);

        // Stores the total weight of the MST
        int sumMST = 0;

        // Start from node 0 with weight 0
        pq.push({0, 0});

        while (!pq.empty())
        {
            // Get the edge with the minimum weight
            auto it = pq.top();
            pq.pop();

            // Weight of the edge
            int wt = it.first;

            // Node to which the edge leads
            int node = it.second;

            // If the node is already included in MST, skip it
            if (vis[node])
            {
                continue;
            }

            // Mark the node as included in MST
            vis[node] = true;

            // Add the edge's weight to the total MST weight
            sumMST += wt;

            // Traverse all adjacent nodes
            for (auto it : adj[node])
            {
                // Adjacent node
                int adjNode = it[0];

                // Weight of the edge to the adjacent node
                int adjWt = it[1];

                // If the adjacent node is not yet included in MST,
                // push it to the heap
                if (!vis[adjNode])
                {
                    pq.push({adjWt, adjNode});
                }
            }
        }

        // Return the total weight of the MST
        return sumMST;
    }
};