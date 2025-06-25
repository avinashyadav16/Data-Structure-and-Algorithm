/**
 *  @file: Course_Schedule_II.cpp
 *  @brief: There are a total of numCourses courses you have to take,
            labeled from 0 to numCourses - 1.
            You are given an array prerequisites where prerequisites[i] = [ai, bi]
            indicates that you must take course bi first if you want to take course ai.

            For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
            Return the ordering of courses you should take to finish all courses.
            If there are many valid answers, return any of them.
            If it is impossible to finish all courses, return an empty array.

            Example 1:
            Input: numCourses = 2, prerequisites = [[1,0]]
            Output: [0,1]
            Explanation: There are a total of 2 courses to take.
            To take course 1 you should have finished course 0. So the correct course order is [0,1].

            Example 2:
            Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
            Output: [0,2,1,3]
            Explanation: There are a total of 4 courses to take.
            To take course 3 you should have finished both courses 1 and 2.
            Both courses 1 and 2 should be taken after you finished course 0.
            So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

            Example 3:
            Input: numCourses = 1, prerequisites = []
            Output: [0]
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    /**
     * @brief Determines the order in which all courses can be finished given the prerequisites.
     *
     * @param numCourses The total number of courses.
     * @param prerequisites A list of prerequisite pairs where each pair [a, b] indicates that course a depends on course b.
     * @return A vector containing the order of courses to be taken, or an empty vector if it's not possible to finish all courses.
     */
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Create an adjacency list to represent the graph of course dependencies.
        vector<vector<int>> adj(numCourses);

        // Populate the adjacency list with the given prerequisites.
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        // Create a vector to store the in-degree (number of incoming edges) for each course.
        vector<int> inDegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        // Create a queue to perform a topological sort.
        queue<int> q;
        // Add all courses with an in-degree of 0 to the queue (i.e., courses with no prerequisites).
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Create a vector to store the topological order of courses.
        vector<int> topo;
        // Perform a topological sort using Kahn's algorithm.
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            // Decrease the in-degree of all neighboring courses by 1.
            for (auto nghbr : adj[node])
            {
                inDegree[nghbr]--;
                // If the in-degree of a neighboring course becomes 0, add it to the queue.
                if (inDegree[nghbr] == 0)
                {
                    q.push(nghbr);
                }
            }
        }

        // If the topological order contains all courses, return the order (i.e., all courses can be finished).
        if (topo.size() == numCourses)
        {
            return topo;
        }

        // Otherwise, return an empty vector (i.e., there is a cycle in the graph, and not all courses can be finished).
        return {};
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    int numCourses = 4;
    vector<int> order = sol.findOrder(numCourses, prerequisites);
    if (!order.empty())
    {
        cout << "The order of courses to be taken is: ";
        for (int course : order)
        {
            cout << course << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "It's not possible to finish all courses." << endl;
    }

    return 0;
}