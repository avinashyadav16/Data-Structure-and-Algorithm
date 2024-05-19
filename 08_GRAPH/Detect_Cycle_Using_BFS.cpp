/**
 *  @file: Detect_Cycle_Using_BFS.cpp
 *  @author: Avinash Yadav
 *  @brief: Detect cycle in the undirected graph using BFS
 *  @date: 19-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to perform BFS
bool BFS(int start, vector<bool> &visited, unordered_map<int, vector<int>> &graph)
{
    // Create a queue for BFS
    queue<pair<int, int>> q; // pair<int, int> stores (vertex, parent)
    q.push({start, -1});     // Starting node has no parent

    while (!q.empty())
    {
        int v = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : graph[v])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push({neighbor, v});
            }
            else if (neighbor != parent)
            {
                // A visited neighbor that is not the parent indicates a cycle
                return true;
            }
        }
    }
    return false;
}

// Function to detect cycle in the graph using BFS
bool hasCycleBFS(unordered_map<int, vector<int>> &graph, int numVertices)
{
    vector<bool> visited(numVertices, false);
    for (int v = 0; v < numVertices; v++)
    {
        if (!visited[v])
        {
            visited[v] = true;
            if (BFS(v, visited, graph))
                return true;
        }
    }
    return false;
}

int main()
{
    // Create a graph using an adjacency list
    unordered_map<int, vector<int>> graph;

    // Add edges to the graph (undirected)
    graph[0] = {1, 2};
    graph[1] = {0, 2};
    graph[2] = {0, 1, 3};
    graph[3] = {2};

    int numVertices = 4;

    if (hasCycleBFS(graph, numVertices))
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";

    return 0;
}