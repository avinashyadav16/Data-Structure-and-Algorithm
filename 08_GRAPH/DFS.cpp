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

// Function to perform DFS iteratively
void DFSIterative(int start, unordered_map<int, vector<int>> &adj)
{
    // Create a stack for DFS
    stack<int> s;

    // To keep track of visited vertices
    unordered_set<int> visited;

    // Push the current source node
    s.push(start);

    while (!s.empty())
    {
        // Pop a vertex from stack and print it
        int v = s.top();
        s.pop();

        // If the vertex is not visited, mark it visited and process it
        if (visited.find(v) == visited.end())
        {
            cout << v << " ";
            visited.insert(v);
        }

        // Get all adjacent vertices of the popped vertex v
        // If an adjacent has not been visited, push it to the stack
        for (int neighbor : adj[v])
        {
            if (visited.find(neighbor) == visited.end())
            {
                s.push(neighbor);
            }
        }
    }
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