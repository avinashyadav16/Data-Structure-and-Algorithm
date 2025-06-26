/**
 *  @file: DisjointSetBySize.cpp
 *  @author: Avinash Yadav
 */

#include <bits/stdc++.h>
using namespace std;

// Disjoint Set (Union-Find) implementation using union by size optimization
class DisjointSet
{
public:
    // Stores the size of each set (number of elements in the set)
    vector<int> size;

    // Stores the parent of each node
    vector<int> parent;

    // Constructor to initialize the Disjoint Set with n elements
    DisjointSet(int n)
    {
        // Initialize size of each set as 1
        size.resize(n + 1, 1);

        // Parent array to keep track of ultimate parent
        parent.resize(n + 1);

        // Initially, every node is its own parent (self root)
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    // Find the ultimate parent of a node with path compression
    int findParent(int node)
    {
        if (node == parent[node])
        {
            // Node is the root of its set
            return node;
        }

        // Path compression: update parent to the root of the set
        return parent[node] = findParent(parent[node]);
    }

    // Union two sets by size (attach smaller set under larger set)
    void unionBySize(int u, int v)
    {
        // Find ultimate parent of u
        int ulm_parent_u = findParent(u);

        // Find ultimate parent of v
        int ulm_parent_v = findParent(v);

        if (ulm_parent_u == ulm_parent_v)
        {
            // Already in the same set, no need to union
            return;
        }

        // Attach the smaller set under the larger set
        if (size[ulm_parent_u] < size[ulm_parent_v])
        {
            // u's root points to v's root
            parent[ulm_parent_u] = ulm_parent_v;

            // Update size of v's set
            size[ulm_parent_v] += size[ulm_parent_u];
        }
        else
        {
            // v's root points to u's root
            parent[ulm_parent_v] = ulm_parent_u;

            // Update size of u's set
            size[ulm_parent_u] += size[ulm_parent_v];
        }
    }
};

int main()
{
    // Create a Disjoint Set with 7 elements (1-based indexing)
    DisjointSet ds(7); 

    // Perform unions
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // Check if 3 and 7 are in the same set before union
    cout << "Before Addition of Edge of 3 and 7: ";
    if (ds.findParent(3) == ds.findParent(7))
    {
        cout << "Same Ultimate Parent." << endl;
    }
    else
    {
        cout << "Different Ultimate Parent." << endl;
    }

    // Union 3 and 7
    ds.unionBySize(3, 7);

    // Check if 3 and 7 are in the same set after union
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