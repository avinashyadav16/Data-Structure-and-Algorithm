/**
 *  @file: Floyd_Warshall.cpp
 *  @author: Avinash Yadav
 *  @brief: Floyd-Warshall algorithm
            The Floyd-Warshall algorithm is used for finding shortest paths in a weighted graph
            with positive or negative edge weights (but with no negative cycles).
            It computes the shortest paths between all pairs of vertices.
 *  @date: 19-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Define the number of vertices in the graph
#define V 4

// A large enough value to represent infinity
#define INF INT_MAX

// Function to print the shortest distance matrix
void printSolution(const vector<vector<int>> &dist)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << "   ";
            }
        }
        cout << endl;
    }
}

// Function to implement Floyd-Warshall algorithm
void floydWarshall(vector<vector<int>> &graph)
{
    // Copy the graph to initialize distance matrix
    vector<vector<int>> dist = graph;

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}

int main()
{
    // Define the graph as a 2D array
    vector<vector<int>> graph = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}};

    // Run the Floyd-Warshall algorithm
    floydWarshall(graph);

    return 0;
}