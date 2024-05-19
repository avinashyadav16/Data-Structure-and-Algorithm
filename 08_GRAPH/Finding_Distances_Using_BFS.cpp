/**
 *  @file: Finding_Distances_Using_BFS.cpp
 *  @author: Avinash Yadav
 *  @brief: Finding distances between vertices in a graph using Breadth-First Search (BFS)
 *  @date: 19-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to perform BFS and find shortest distances
vector<int> bfsDistances(unordered_map<int, vector<int>> &graph, int start, int numVertices)
{
    // Initialize distances with -1 (unvisited)
    vector<int> distances(numVertices, -1);

    // Create a queue for BFS
    queue<int> q;
    q.push(start);

    // Distance to the start vertex is 0
    distances[start] = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        // Traverse all adjacent vertices of the current vertex
        for (int neighbor : graph[current])
        {
            if (distances[neighbor] == -1)
            {
                // If the neighbor hasn't been visited yet
                q.push(neighbor);

                // Set distance to the neighbor
                distances[neighbor] = distances[current] + 1;
            }
        }
    }
    return distances;
}

int main()
{
    // Create a graph using an adjacency list
    unordered_map<int, vector<int>> graph;
    int numVertices = 6;

    // Add edges to the graph (undirected)
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 4, 5};
    graph[4] = {1, 2, 3, 5};
    graph[5] = {3, 4};

    // Start BFS from vertex 0
    vector<int> distances = bfsDistances(graph, 0, numVertices);

    // Print distances from the start vertex
    cout << "Distances from vertex 0:" << endl;
    for (int i = 0; i < numVertices; i++)
    {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}