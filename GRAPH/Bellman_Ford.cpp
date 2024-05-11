/**
*  @file: Bellman_Ford.cpp
*  @author: Avinash Yadav   | AP22110010366
*  @brief: 1. Provide the implementation of the following problems in your preferred
              programming language (such as Python, Java, or C++).
                    b. Bellman Ford
*  @date: 26-04-2024
*/

#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

void bellmanFord(vector<Edge> edges, int V, int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; ++i)
    {
        for (const auto &edge : edges)
        {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto &edge : edges)
    {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;
        
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    cout << "Vertex   Distance from Source" << endl;
    for (int i = 0; i < V; ++i)
    {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main()
{
    // Number of vertices
    int V = 5;

    // Adjacency list representation of graph
    // (src, dest, weight) triples are representation of the graph
    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}};

    // Source vertex
    int src = 0;

    bellmanFord(edges, V, src);

    return 0;
}