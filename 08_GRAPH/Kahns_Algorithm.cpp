/**
 *  @file: Kahns_Algorithm.cpp
 *  @author: Avinash Yadav
 *  @date: 21-06-2025
 *  @link: https://www.geeksforgeeks.org/problems/topological-sort/1
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to perform topological sort using Kahn's Algorithm
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // Create adjacency list for the directed graph
        vector<vector<int>> adjLS(V);

        // Vector to store indegree of each vertex
        vector<int> indegree(V, 0);

        // Build the adjacency list and fill indegree array
        for (auto &edge : edges)
        {
            // Add edge from edge[0] to edge[1]
            adjLS[edge[0]].push_back(edge[1]);

            // Increment indegree of destination node
            indegree[edge[1]]++;
        }

        // Vector to store the result of topological sort
        vector<int> topoSort;

        // Queue to process all nodes with indegree 0
        queue<int> q;

        // Push all nodes with indegree 0 into the queue
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Process nodes in queue
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // Add current node to topological order
            topoSort.push_back(node);

            // Decrease indegree of all adjacent nodes
            for (auto &adj : adjLS[node])
            {
                indegree[adj]--;
                
                // If indegree becomes 0, add to queue
                if (indegree[adj] == 0)
                {
                    q.push(adj);
                }
            }
        }

        // Return the topological order
        return topoSort;
    }
};