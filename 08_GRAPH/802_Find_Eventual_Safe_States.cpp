/**
*  @file: 802_Find_Eventual_Safe_States.cpp
*  @author: Avinash Yadav
*  @date: 21-06-2025
*  @link: https://leetcode.com/problems/find-eventual-safe-states/description/
*  @brief: There is a directed graph of n nodes with each node labeled from 0 to n - 1.
            The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i,
            meaning there is an edge from node i to each node in graph[i].

            A node is a terminal node if there are no outgoing edges.
            A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

            Return an array containing all the safe nodes of the graph.
            The answer should be sorted in ascending order.

            Example 1:
            Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
            Output: [2,4,5,6]
            Explanation: The given graph is shown above.
            Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
            Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6

            Example 2:
            Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
            Output: [4]
            Explanation:
            Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
*/

#include <bits/stdc++.h>
using namespace std;

// DFS-based solution to find all eventual safe nodes in a directed graph
class Solution_DFS
{
public:
    // Function for DFS traversal to detect cycles and mark safe nodes
    bool dfsTraversal(int node, vector<vector<int>> &graph,
                      vector<bool> &vis, vector<bool> &pathVis,
                      vector<bool> &check)
    {
        // Mark current node as visited
        vis[node] = true;

        // Mark node as part of current DFS path
        pathVis[node] = true;

        // Assume node is not safe initially
        check[node] = false;

        // Traverse all adjacent nodes
        for (auto &adj : graph[node])
        {
            // If adjacent node is not visited, recurse
            if (!vis[adj])
            {
                if (dfsTraversal(adj, graph, vis, pathVis, check))
                {
                    // If a cycle is detected in the DFS subtree,
                    // return true
                    return true;
                }
            }
            // If adjacent node is already in the current path,
            // a cycle is found
            else if (pathVis[adj])
            {
                return true;
            }
        }

        // If no cycle is found, mark node as safe
        check[node] = true;

        // Remove node from current DFS path
        pathVis[node] = false;

        // No cycle detected from this node
        return false;
    }

    // Main function to return all eventual safe nodes
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();

        // Tracks visited nodes
        vector<bool> vis(V, false);

        // Tracks nodes in current DFS path
        vector<bool> pathVis(V, false);

        // Marks safe nodes
        vector<bool> check(V, false);

        // Stores result
        vector<int> safeNodes;

        // Run DFS for each node
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsTraversal(i, graph, vis, pathVis, check);
            }
        }

        // Collect all nodes marked as safe
        for (int i = 0; i < V; i++)
        {
            if (check[i])
            {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};

// BFS-based solution using Topological Sort (Kahn's Algorithm)
// to find all eventual safe nodes
class Solution_BFS_TopoSort
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();

        // indegree[i]:
        // number of outgoing edges from node i in the original graph
        vector<int> indegree(V, 0);

        // revGraph: reversed graph,
        // where revGraph[i] contains all nodes that have an edge to i
        vector<vector<int>> revGraph(V);

        // Build the reversed graph and compute indegrees
        for (int i = 0; i < V; i++)
        {
            for (auto it : graph[i])
            {
                // Reverse the edge
                revGraph[it].push_back(i);

                // Count outgoing edges for original node
                indegree[i]++;
            }
        }

        // Queue for BFS
        queue<int> q;

        // Stores all safe nodes
        vector<int> safeNodes;

        // All terminal nodes (with zero outgoing edges) are initially safe
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Process nodes in BFS manner
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // This node is safe
            safeNodes.push_back(node);

            // For all nodes
            // that point to the current node in the reversed graph
            for (auto it : revGraph[node])
            {
                // Remove the edge to the current node
                indegree[it]--;

                // If this node now has no outgoing edges,
                // it is safe
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        // Sort the result as required by the problem statement
        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};