/**
*  @file: Bellman_Ford_Algorithm.cpp
*  @author: Avinash Yadav
*  @date: 22-06-2025
*  @link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
*  @brief: Given an weighted graph with V vertices numbered from 0 to V-1 and E edges,
            represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight.
            You are also given a source vertex src.

            Your task is to compute the shortest distances from the source to all other vertices.
            If a vertex is unreachable from the source, its distance should be marked as 10^8.
            Additionally, if the graph contains a negative weight cycle,
            return [-1] to indicate that shortest paths cannot be reliably computed.

            Examples:
                Input: V = 5, edges[][] = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]], src = 0
                Output: [0, 5, 6, 6, 7]
                Explanation: Shortest Paths:
                For 0 to 1 minimum distance will be 5. By following path 0 → 1
                For 0 to 2 minimum distance will be 6. By following path 0 → 1  → 2
                For 0 to 3 minimum distance will be 6. By following path 0 → 1  → 2 → 4 → 3
                For 0 to 4 minimum distance will be 7. By following path 0 → 1  → 2 → 4

                Input: V = 4, edges[][] = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]], src = 0
                Output: [-1]
                Explanation: The graph contains a negative weight cycle formed by the path 1 → 2 → 3 → 1,
                where the total weight of the cycle is negative.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to implement Bellman-Ford algorithm
    // V: number of vertices
    // edges: list of edges, where each edge is represented as [u, v, w]
    // src: source vertex
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        // Initialize distance array with a large value
        // (1e8) to represent infinity
        vector<int> dist(V, 1e8);

        // Distance to the source is always 0
        dist[src] = 0;

        // Relax all edges V-1 times
        // Ensures that the shortest path from src to any vertex is found
        for (int i = 0; i < V - 1; i++)
        {
            for (auto &it : edges)
            {
                int u = it[0];  // source vertex of the edge
                int v = it[1];  // destination vertex of the edge
                int wt = it[2]; // weight of the edge

                // If the distance to u is not infinity and
                // the path through u to v is shorter, update dist[v]
                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative weight cycles
        // If we can relax any edge further,
        // then there is a negative weight cycle
        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            // If a shorter path is still found, negative cycle exists
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                // Return [-1] to indicate negative weight cycle
                return {-1};
            }
        }

        // Return the computed shortest distances
        return dist;
    }
};
