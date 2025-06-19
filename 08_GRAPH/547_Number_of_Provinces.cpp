/**
*  @file: 547_Number_of_Provinces.cpp
*  @author: Avinash Yadav
*  @date: 17-06-2025
*  @link: https://leetcode.com/problems/number-of-provinces/description/
*  @brief: There are n cities. Some of them are connected, while some are not.
            If city a is connected directly with city b, and city b is connected directly with city c,
            then city a is connected indirectly with city c.
            A province is a group of directly or indirectly connected cities and no other cities outside of the group.

            You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

            Return the total number of provinces.

            Example 1:
                Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
                Output: 2

            Example 2:
                Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
                Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

// Using DFS (Depth-First Search) Recursion to find the number of provinces
class Solution1
{
public:
    // Function to perform DFS traversal from a given node
    void dfsTraversal(int node, vector<int> adjLS[], vector<bool> &isVisited)
    {
        // Mark the current node as visited
        isVisited[node] = true;

        // Visit all unvisited neighbors
        for (int neighbor : adjLS[node])
        {
            if (!isVisited[neighbor])
            {
                dfsTraversal(neighbor, adjLS, isVisited);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int nodes = isConnected.size();

        // Adjacency list representation
        vector<int> adjLS[nodes];

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                // If there is a connection and it's not a self-loop
                if (i != j && isConnected[i][j] == 1)
                {
                    // Since the graph is undirected
                    adjLS[i].push_back(j);
                    adjLS[j].push_back(i);
                }
            }
        }

        // Track visited nodes
        vector<bool> isVisited(nodes + 1, false);

        // Count of provinces
        int totalPro = 0;

        // Traverse all nodes
        for (int i = 0; i < nodes; i++)
        {
            // If node is not visited, it's a new province
            if (!isVisited[i])
            {
                totalPro++;

                // Visit all nodes in this province
                dfsTraversal(i, adjLS, isVisited);
            }
        }

        return totalPro;
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{

    vector<vector<int>> isConnected1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}; // Output: 2
    vector<vector<int>> isConnected2 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}; // Output: 3

    Solution1 sol1;
    cout << "OUTPUT IS: " << endl;
    cout << sol1.findCircleNum(isConnected1) << endl;
    cout << sol1.findCircleNum(isConnected2) << endl;

    return 0;
}
