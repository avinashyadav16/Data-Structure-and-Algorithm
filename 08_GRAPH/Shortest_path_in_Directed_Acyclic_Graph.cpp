/**
*  @file: Shortest_path_in_Directed_Acyclic_Graph.cpp
*  @author: Avinash Yadav
*  @date: 21-06-2025
*  @link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
*  @brief: Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E,
            where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

            Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex,
            then return -1 for that vertex.

            Examples :
                Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
                Output: [0, 2, 1, -1]
                Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1.
                There is no way we can reach 3, so it's -1 for 3.

                Input: V = 6, E = 7, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]
                Output: [0, 2, 3, 6, 1, 5]
                Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
                Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.
                Shortest path from 0 to 4 is 0->4 with edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to perform DFS and store nodes in topological order
    void DFS_TopoSort(int node, vector<pair<int, int>> adj[],
                      int vis[], stack<int> &st)
    {
        // Mark the current node as visited
        vis[node] = 1;

        // Visit all adjacent nodes (neighbors)
        for (auto it : adj[node])
        {
            // Neighbor node
            int v = it.first;

            // If neighbor is not visited, recursively visit it
            if (!vis[v])
            {
                DFS_TopoSort(v, adj, vis, st);
            }
        }

        // After visiting all neighbors, push current node to stack
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        // Create adjacency list for the graph
        vector<pair<int, int>> adj[V];

        // Fill adjacency list with edges and their weights
        for (int i = 0; i < E; i++)
        {
            int u = edges[i][0];  // From node
            int v = edges[i][1];  // To node
            int wt = edges[i][2]; // Edge weight

            adj[u].push_back({v, wt});
        }

        int vis[V] = {0}; // Visited array for DFS

        stack<int> st; // Stack to store topological order

        // Perform DFS from every unvisited node to get topological order
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                DFS_TopoSort(i, adj, vis, st);
            }
        }

        // Initialize distances to all nodes as infinity (1e9)
        vector<int> dist(V, 1e9);

        dist[0] = 0; // Distance to source node is 0

        // Process nodes in topological order
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            // If the node has been reached before
            // (distance is not infinity)
            if (dist[node] != 1e9)
            {
                // Relax all adjacent edges
                for (auto it : adj[node])
                {
                    int v = it.first;   // Neighbor node
                    int wt = it.second; // Edge weight

                    // If a shorter path to v is found, update it
                    if (dist[node] + wt < dist[v])
                    {
                        dist[v] = wt + dist[node];
                    }
                }
            }
        }

        // Replace all unreachable nodes' distances with -1
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == 1e9)
            {
                dist[i] = -1;
            }
        }

        // Return the shortest distances from source to all nodes
        return dist; 
    }
};
