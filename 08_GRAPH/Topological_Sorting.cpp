/**
 *  @file: Topological_Sorting.cpp
 *  @author: Avinash Yadav
 *  @brief: Topological sorting of a directed acyclic graph (DAG) is a linear ordering of its vertices
            such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering.
            This can be achieved using Depth-First Search (DFS).
            During the DFS, when we finish processing a vertex, we push it onto a stack.
            The stack will then contain the vertices in topologically sorted order when the DFS is complete.
 *  @date: 19-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to perform DFS and push finished vertices to stack
void topologicalSortDFS(int v, unordered_map<int, vector<int>> &graph, vector<bool> &visited, stack<int> &Stack)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all vertices adjacent to this vertex
    for (int neighbor : graph[v])
    {
        if (!visited[neighbor])
        {
            topologicalSortDFS(neighbor, graph, visited, Stack);
        }
    }

    // Push current vertex to stack which stores the result
    Stack.push(v);
}

// Function to perform topological sort
vector<int> topologicalSort(unordered_map<int, vector<int>> &graph, int numVertices)
{
    stack<int> Stack;
    vector<bool> visited(numVertices, false);

    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < numVertices; i++)
    {
        if (!visited[i])
        {
            topologicalSortDFS(i, graph, visited, Stack);
        }
    }

    // Store the topological sort in a vector
    vector<int> topOrder;
    while (!Stack.empty())
    {
        topOrder.push_back(Stack.top());
        Stack.pop();
    }

    return topOrder;
}

int main()
{
    // Create a graph using an adjacency list
    unordered_map<int, vector<int>> graph;

    // Add edges to the graph (directed)
    graph[0] = {1, 2};
    graph[1] = {2, 3};
    graph[2] = {3};
    graph[3] = {4};
    graph[4] = {};

    int numVertices = 5;

    vector<int> topOrder = topologicalSort(graph, numVertices);

    cout << "Topological Sort of the given graph:\n";
    for (int i = 0; i < topOrder.size(); i++)
    {
        cout << topOrder[i] << " ";
    }
    cout << endl;

    return 0;
}