/**
 *  @file: DFS.cpp
 *  @author: Avinash Yadav
 *  @brief: Code for Graph traversal by using DFS
 *  @date: 16-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to add an edge to the graph
void addEdge(vector<vector<int>> &adj, int u, int v)
{
    // Add v to u’s list.
    adj[u].push_back(v);
}

// DFS utility function used by DFS
void DFSUtil(const vector<vector<int>> &adj, int v, vector<bool> &visited)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    for (auto i : adj[v])
    {
        if (!visited[i])
        {
            DFSUtil(adj, i, visited);
        }
    }
}

// DFS traversal from a given source v
void DFS(const vector<vector<int>> &adj, int V, int v)
{
    // Mark all vertices as not visited
    vector<bool> visited(V, false);

    DFSUtil(adj, v, visited);
}

int main()
{
    // Number of vertices
    int V = 4;

    // Adjacency list
    vector<vector<int>> adj(V);

    // Adding edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);

    cout << "Depth First Traversal (starting from vertex 2): ";
    DFS(adj, V, 2);

    return 0;
}