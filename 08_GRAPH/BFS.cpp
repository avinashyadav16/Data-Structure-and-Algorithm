/**
 *  @file: BFS.cpp
 *  @author: Avinash Yadav
 *  @brief: Code for Graph traversal by using BFS
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

// BFS traversal from a given source s
void BFS(const vector<vector<int>> &adj, int V, int s)
{
    // Mark all vertices as not visited
    vector<bool> visited(V, false);

    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        // Dequeue a vertex from the queue and print it
        s = q.front();
        cout << s << " ";
        q.pop();

        // Get all adjacent vertices of the dequeued vertex s
        // If an adjacent has not been visited, then mark it visited and enqueue it
        for (auto i : adj[s])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
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

    // Adding edges to the graph by using function
    // addEdge(adj, 0, 1);
    // addEdge(adj, 0, 2);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 2, 0);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 3, 3);

    // Adding edges to the graph without using function
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    cout << "Breadth First Traversal (starting from vertex 2): ";
    BFS(adj, V, 2);

    return 0;
}