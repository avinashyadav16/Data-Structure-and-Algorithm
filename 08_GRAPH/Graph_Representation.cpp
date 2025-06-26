#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////
// ADJACENCY MATRIX
//////////////////////////////////////////////////////////////////////////////////
class Solution1
{
public:
    void adjMatrixRepresentation()
    {
        int vertex;
        cout << "Number of Nodes: ";
        cin >> vertex;

        int edge;
        cout << "Number of Edges: ";
        cin >> edge;

        vector<vector<int>> adjMat(vertex + 1, vector<int>(vertex + 1, 0));

        for (int i = 1; i <= edge; i++)
        {
            cout << "Edge: ";

            int u, v;
            cin >> u >> v;

            if (u >= 1 && u <= vertex && v >= 1 && v <= vertex)
            {
                adjMat[u][v] = 1;
                adjMat[v][u] = 1;
            }
            else
            {
                cout << "Invalid edge! Enter between 1 and " << vertex << "." << endl;
                i--;
            }
        }

        cout << "Given Graph (Adjacency Matrix) is: " << endl;
        for (int i = 1; i <= vertex; i++)
        {
            for (int j = 1; j <= vertex; j++)
            {
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

//////////////////////////////////////////////////////////////////////////////////
// ADJACENCY LIST
//////////////////////////////////////////////////////////////////////////////////
class Solution2
{
public:
    void adjListRepresentation()
    {
        int vertex;
        cout << "Number of Nodes: ";
        cin >> vertex;

        int edge;
        cout << "Number of Edges: ";
        cin >> edge;

        vector<vector<int>> adjList(vertex + 1);

        for (int i = 1; i <= edge; i++)
        {
            cout << "Edge: ";
            int u, v;
            cin >> u >> v;

            if (u >= 1 && u <= vertex && v >= 1 && v <= vertex)
            {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
            else
            {
                cout << "Invalid edge! Enter between 1 and " << vertex << "." << endl;
                i--;
            }
        }

        cout << "Given Graph (Adjacency List) is: " << endl;
        for (int i = 1; i <= vertex; i++)
        {
            cout << i << ": ";
            for (int v : adjList[i])
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution1 sol1;
    sol1.adjMatrixRepresentation();

    Solution2 sol2;
    sol2.adjListRepresentation();

    return 0;
}

/*
Number of Nodes: 5
Number of Edges: 6
Edge: 1 2
Edge: 1 3
Edge: 2 4
Edge: 3 4
Edge: 2 5
Edge: 3 5
Given Graph (Adjacency Matrix) is:
0 1 1 0 0
1 0 0 1 1
1 0 0 1 1
0 1 1 0 0
0 1 1 0 0


Number of Nodes: 5
Number of Edges: 6
Edge: 1 2
Edge: 1 3
Edge: 2 4
Edge: 3 4
Edge: 2 5
Edge: 3 5
Given Graph (Adjacency List) is:
1: 2 3
2: 1 4 5
3: 1 4 5
4: 2 3
5: 2 3
*/