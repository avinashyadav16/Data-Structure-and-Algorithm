/**
 *  @file: Detect_Cycle_Using_DFS.cpp
 *  @author: Avinash Yadav
 *  @brief: Detect cycle in the undirected graph using DFS
 *  @date: 19-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to perform DFS
bool DFS(int v, int parent, vector<bool> &visited, unordered_map<int, vector<int>> &graph)
{
    visited[v] = true;
    for (int neighbor : graph[v])
    {
        if (!visited[neighbor])
        {
            if (DFS(neighbor, v, visited, graph))
                return true;
        }
        else if (neighbor != parent)
        {
            return true;
        }
    }
    return false;
}

// Function to detect cycle in the graph using DFS
bool hasCycleDFS(unordered_map<int, vector<int>> &graph, int numVertices)
{
    vector<bool> visited(numVertices, false);
    for (int v = 0; v < numVertices; v++)
    {
        if (!visited[v])
        {
            if (DFS(v, -1, visited, graph))
                return true;
        }
    }
    return false;
}

int main()
{
    unordered_map<int, vector<int>> graph;
    graph[0] = {1, 2};
    graph[1] = {0, 2};
    graph[2] = {0, 1, 3};
    graph[3] = {2};

    int numVertices = 4;

    if (hasCycleDFS(graph, numVertices))
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";

    return 0;
}