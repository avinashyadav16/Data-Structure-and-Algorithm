/**
*  @file: BiConnected_Components.cpp
*  @author: Avinash Yadav   | AP22110010366
*  @brief: 1. Provide the implementation of the following problems in your preferred
              programming language (such as Python, Java, or C++).
                    a. Biconnected Components
*  @date: 26-04-2024
*/

#include <bits/stdc++.h>
using namespace std;

void DFS(int u,
         int parent,
         vector<int> &disc,
         vector<int> &low,
         stack<pair<int, int>> &edges,
         vector<vector<int>> &bcc,
         const vector<vector<int>> &adj)
{
    static int time = 0;
    disc[u] = low[u] = ++time;
    int children = 0;

    for (int v : adj[u])
    {
        if (v == parent)
            continue;

        if (!disc[v])
        {
            children++;
            edges.push({u, v});
            DFS(v, u, disc, low, edges, bcc, adj);
            low[u] = min(low[u], low[v]);

            if ((disc[u] == 1 && children > 1) || (disc[u] > 1 && low[v] >= disc[u]))
            {
                vector<int> currentBCC;
                while (edges.top() != make_pair(u, v))
                {
                    currentBCC.push_back(edges.top().first);
                    currentBCC.push_back(edges.top().second);
                    edges.pop();
                }
                currentBCC.push_back(edges.top().first);
                currentBCC.push_back(edges.top().second);
                edges.pop();
                bcc.push_back(currentBCC);
            }
        }
        else if (disc[v] < disc[u])
        {
            edges.push({u, v});
            low[u] = min(low[u], disc[v]);
        }
    }
}

// Function to find biconnected components
void findBiconnectedComponents(int V, const vector<vector<int>> &adj)
{
    vector<int> disc(V, 0), low(V, 0);
    stack<pair<int, int>> edges;
    vector<vector<int>> bcc;

    for (int u = 0; u < V; ++u)
    {
        if (!disc[u])
            DFS(u, -1, disc, low, edges, bcc, adj);
    }

    // Print biconnected components
    cout << "Biconnected Components:" << endl;
    for (const auto &component : bcc)
    {
        for (int v : component)
            cout << v << " ";
        cout << endl;
    }
}

int main()
{
    // Number of vertices
    int V = 7;

    vector<vector<int>> adj(V);

    // Add edges to the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[3].push_back(1);
    adj[3].push_back(5);
    adj[4].push_back(1);
    adj[4].push_back(5);
    adj[4].push_back(6);
    adj[5].push_back(3);
    adj[5].push_back(4);
    adj[5].push_back(6);
    adj[6].push_back(4);
    adj[6].push_back(5);

    // Find biconnected components
    findBiconnectedComponents(V, adj);

    return 0;
}