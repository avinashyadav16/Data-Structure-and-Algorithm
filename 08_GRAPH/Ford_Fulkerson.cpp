/**
*  @file: Ford_Fulkerson.cpp
*  @author: Avinash Yadav   | AP22110010366
*  @brief: 1. Provide the implementation of the following problems in your preferred
              programming language (such as Python, Java, or C++).
                    c. Ford-Fulkerson method.
*  @date: 26-04-2024
*/

#include <bits/stdc++.h>
using namespace std;

// Structure to represent an edge in the flow network
struct Edge
{
    int v, u, capacity, flow;
};

// Function to find augmenting paths using Breadth First Search (BFS)
bool bfs(vector<vector<int>> &residual, vector<int> &parent, int source, int sink)
{
    int V = residual.size();
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; ++v)
        {
            if (!visited[v] && residual[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[sink];
}

// Function to apply Ford-Fulkerson algorithm and find the maximum flow
int fordFulkerson(vector<vector<int>> &graph, int source, int sink)
{
    int V = graph.size();
    vector<vector<int>> residual = graph;
    vector<int> parent(V);
    int maxFlow = 0;

    while (bfs(residual, parent, source, sink))
    {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            pathFlow = min(pathFlow, residual[u][v]);
        }

        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    // Number of vertices and edges
    int V = 4;
    int E = 5;

    vector<vector<int>> graph(V, vector<int>(V, 0));
    graph[0][1] = 10;
    graph[0][2] = 5;
    graph[1][2] = 15;
    graph[1][3] = 20;
    graph[2][3] = 10;

    int source = 0;
    int sink = 3;

    int maxFlow = fordFulkerson(graph, source, sink);
    cout << "Maximum flow from source " << source << " to sink " << sink << ": " << maxFlow << endl;

    return 0;
}