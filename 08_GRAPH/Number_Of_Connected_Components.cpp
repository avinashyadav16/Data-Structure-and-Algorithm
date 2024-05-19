/**
 *  @file: Number_Of_Connected_Components.cpp
 *  @author: Avinash Yadav
 *  @brief: To find the number of connected components in an undirected graph
 *          Each new DFS call represents a new connected component.
 *  @date: 19-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to perform DFS
void DFS(int v, unordered_map<int, vector<int>> &graph, vector<bool> &visited)
{
    visited[v] = true;
    for (int neighbor : graph[v])
    {
        if (!visited[neighbor])
        {
            DFS(neighbor, graph, visited);
        }
    }
}

// Function to count the number of connected components in the graph
int countConnectedComponents(unordered_map<int, vector<int>> &graph, int numVertices)
{
    vector<bool> visited(numVertices, false);
    int numComponents = 0;

    for (int v = 0; v < numVertices; v++)
    {
        if (!visited[v])
        {
            DFS(v, graph, visited);
            numComponents++;
        }
    }

    return numComponents;
}

int main()
{
    // Create a graph using an adjacency list
    unordered_map<int, vector<int>> graph;

    // Add edges to the graph (undirected)
    graph[0] = {1};
    graph[1] = {0, 2};
    graph[2] = {1};
    graph[3] = {4};
    graph[4] = {3};

    int numVertices = 5;

    int numComponents = countConnectedComponents(graph, numVertices);
    cout << "Number of connected components: " << numComponents << endl;

    return 0;
}