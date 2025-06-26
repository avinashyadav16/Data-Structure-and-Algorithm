/**
 *  @file: DisjointSetByRank.cpp
 *  @author: Avinash Yadav
 */

#include <bits/stdc++.h>
using namespace std;

// Disjoint Set (Union-Find) implementation with Union by Rank and Path Compression.
// This data structure efficiently supports union and find operations on disjoint sets.
// It is commonly used in Kruskal's algorithm and to detect cycles in graphs.

class DisjointSet
{
public:
    // rank[i] keeps track of the "rank"
    // (approximate depth) of the tree rooted at i.
    vector<int> rank;

    // parent[i] stores the parent of node i.
    // If parent[i] == i, then i is a root.
    vector<int> parent;

    // Constructor initializes n disjoint sets
    // (from 0 to n-1).
    DisjointSet(int n)
    {
        // Initialize all ranks to 0.
        rank.resize(n + 1, 0);

        // Allocate space for parent array.
        parent.resize(n + 1);

        // Initially, each node is its own parent (self root).
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Find operation with path compression.
    // Returns the ultimate parent (root) of the set containing 'node'.
    // Path compression flattens the structure, making future finds faster.
    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        // Recursively find the root and compress the path.
        return parent[node] = findParent(parent[node]);
    }

    // Union operation by rank.
    // Merges the sets containing nodes 'u' and 'v'.
    // The root with lower rank is attached to the root with higher rank.
    // If ranks are equal, one becomes the parent and its rank increases by 1.
    void unionByRank(int u, int v)
    {
        int ulm_parent_u = findParent(u);
        int ulm_parent_v = findParent(v);

        // If both nodes have the same root, they are already in the same set.
        if (ulm_parent_u == ulm_parent_v)
        {
            return;
        }

        // Attach the tree with lower rank to the one with higher rank.
        if (rank[ulm_parent_u] < rank[ulm_parent_v])
        {
            parent[ulm_parent_u] = ulm_parent_v;
        }
        else if (rank[ulm_parent_v] < rank[ulm_parent_u])
        {
            parent[ulm_parent_v] = ulm_parent_u;
        }
        else
        {
            // If ranks are equal,
            // make one root the parent and increment its rank.
            parent[ulm_parent_u] = ulm_parent_v;
            rank[ulm_parent_v]++;
        }
    }
};

int main()
{
    // Create a DisjointSet for 7 elements (0 to 6).
    DisjointSet ds(7);

    // Perform unions to group nodes into sets.
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // Check if nodes 3 and 7 are in the same set before union.
    cout << "Before Addition of Edge of 3 and 7: ";
    if (ds.findParent(3) == ds.findParent(7))
    {
        cout << "Same Ultimate Parent." << endl;
    }
    else
    {
        cout << "Different Ultimate Parent." << endl;
    }

    // Union nodes 3 and 7, connecting their sets.
    ds.unionByRank(3, 7);

    // Check again if nodes 3 and 7 are now in the same set.
    cout << "After Addition of Edge of 3 and 7: ";
    if (ds.findParent(3) == ds.findParent(7))
    {
        cout << "Same Ultimate Parent." << endl;
    }
    else
    {
        cout << "Different Ultimate Parent." << endl;
    }

    return 0;
}