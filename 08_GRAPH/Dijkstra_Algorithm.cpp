/**
*  @file: Dijkstra_Algorithm.cpp
*  @author: Avinash Yadav
*  @date: 21-06-2025
*  @link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
*  @brief: Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges,
            represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
            You have to find the shortest distance of all the vertices from the source vertex src,
            and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

            Note: The Graph is connected and doesn't contain any negative weight edge.

            Examples:

            Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
            Output: [4, 3, 0]
            Explanation:
                Shortest Paths:
                For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
                For 2 to 1 minimum distance will be 3. By following path 2 -> 1
                For 2 to 2 minimum distance will be 0. By following path 2 -> 2

            Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
            Output: [0, 4, 8, 10, 10]
            Explanation:
                Shortest Paths:
                For 0 to 1 minimum distance will be 4. By following path 0 -> 1
                For 0 to 2 minimum distance will be 8. By following path 0 -> 2
                For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3
                For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_PQ
{
public:
    // Function to implement Dijkstra's algorithm
    // V: number of vertices
    // edges: list of edges where each edge is [u, v, w]
    // src: source vertex
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Create adjacency list for the undirected weighted graph
        // Each entry adjList[u] contains pairs (v, w) meaning edge u-v with weight w
        vector<pair<int, int>> adjList[V];

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // Since the graph is undirected, add both directions
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        // Min-heap priority queue to get the node with the smallest distance
        // Each element is a pair (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialize distances to all vertices as infinity (1e9)
        vector<int> dist(V, 1e9);

        // Distance to source is 0
        pq.push({0, src});
        dist[src] = 0;

        // Main loop of Dijkstra's algorithm
        while (!pq.empty())
        {
            // Get the node with the smallest distance
            int currDis = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            // Traverse all adjacent nodes
            for (auto &it : adjList[currNode])
            {
                int adjNode = it.first;
                int edgeWeight = it.second;

                // If a shorter path to adjNode is found
                if (currDis + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = currDis + edgeWeight;
                    // Push the updated distance to the priority queue
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // Return the shortest distances from src to all vertices
        return dist;
    }
};

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

class Solution_SET
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // Create adjacency list
        // where each node has a list of (neighbor, weight) pairs
        vector<pair<int, int>> adjList[V];

        // Build the adjacency list from the edge list
        for (auto &edge : edges)
        {
            int u = edge[0]; // source vertex
            int v = edge[1]; // destination vertex
            int w = edge[2]; // edge weight

            // Add edge u->v
            adjList[u].push_back({v, w});

            // Add edge v->u (since the graph is undirected)
            adjList[v].push_back({u, w});
        }

        // Set to store pairs of (distance, node)
        // for efficient min extraction and updates
        set<pair<int, int>> st;

        // Initialize distances to all vertices as infinity (1e9)
        vector<int> dist(V, 1e9);

        // Distance to source is 0, insert into set
        st.insert({0, src});
        dist[src] = 0;

        // Main loop:
        // process nodes with the smallest current distance
        while (!st.empty())
        {
            // Extract the node with the minimum distance
            auto it = *(st.begin());

            // Current shortest distance to currNode
            int currDis = it.first;

            // Current node being processed
            int currNode = it.second;

            // Remove the node from the set
            st.erase(it);

            // Traverse all adjacent nodes of currNode
            for (auto &it : adjList[currNode])
            {
                // Neighbor node
                int adjNode = it.first;

                // Weight of edge to neighbor
                int edgeWeight = it.second;

                // If a shorter path to adjNode is found
                if (currDis + edgeWeight < dist[adjNode])
                {
                    // If adjNode was previously discovered,
                    // remove the old entry from set
                    if (dist[adjNode] != 1e9)
                    {
                        st.erase({dist[adjNode], adjNode});
                    }

                    // Update distance to adjNode
                    dist[adjNode] = currDis + edgeWeight;

                    // Insert updated distance & node into set
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        // Return shortest distances from src to all vertices
        return dist;
    }
};