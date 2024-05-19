/**
 *  @file: Dijkstra.cpp
 *  @author: Avinash Yadav
 *  @brief: Dijkstra's algorithm is used to find the shortest paths
            from a single source vertex to all other vertices in a weighted graph with non-negative edge weights.
            It uses a priority queue to explore the nearest vertices first, ensuring that the shortest path to each vertex is found.
 *  @date: 19-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Define a pair for storing the vertex and its distance from the source
typedef pair<int, int> iPair;

// Function to perform Dijkstra's algorithm
vector<int> dijkstra(unordered_map<int, vector<iPair>> &graph, int src, int numVertices)
{
    // Create a priority queue to store vertices that are being preprocessed
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    // Create a vector for distances and initialize all distances as infinite (INT_MAX)
    vector<int> dist(numVertices, INT_MAX);

    // Insert the source itself in priority queue and initialize its distance as 0
    pq.push(make_pair(0, src));
    dist[src] = 0;

    // Loop until the priority queue is empty
    while (!pq.empty())
    {
        // The first vertex in the pair is the minimum distance vertex, extract it from priority queue
        int u = pq.top().second;
        pq.pop();

        // Get all adjacent vertices of the dequeued vertex u
        for (auto &neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If there is a shorter path to v through u
            if (dist[v] > dist[u] + weight)
            {
                // Update distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}

int main()
{
    // Create a graph using an adjacency list
    unordered_map<int, vector<iPair>> graph;
    int numVertices = 5;

    // Add edges to the graph (directed)
    graph[0].push_back(make_pair(1, 10));
    graph[0].push_back(make_pair(4, 5));
    graph[1].push_back(make_pair(2, 1));
    graph[1].push_back(make_pair(4, 2));
    graph[2].push_back(make_pair(3, 4));
    graph[3].push_back(make_pair(2, 6));
    graph[4].push_back(make_pair(1, 3));
    graph[4].push_back(make_pair(2, 9));
    graph[4].push_back(make_pair(3, 2));

    // Source vertex
    int src = 0;

    // Perform Dijkstra's algorithm
    vector<int> distances = dijkstra(graph, src, numVertices);

    // Print the shortest distances from the source to each vertex
    cout << "Vertex Distance from Source " << src << endl;
    for (int i = 0; i < numVertices; i++)
    {
        cout << i << "\t\t" << distances[i] << endl;
    }

    return 0;
}