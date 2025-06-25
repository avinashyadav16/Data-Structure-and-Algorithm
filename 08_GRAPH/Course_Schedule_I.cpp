/**
 *  @file: Course_Schedule_I.cpp
 *  @author: Avinash Yadav
 *  @brief: There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
            You are given an array prerequisites where prerequisites[i] = [ai, bi]
            indicates that you must take course bi first if you want to take course ai.

            For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
            Return true if you can finish all courses. Otherwise, return false.

            Example 1:
            Input: numCourses = 2, prerequisites = [[1,0]]
            Output: true
            Explanation: There are a total of 2 courses to take.
            To take course 1 you should have finished course 0. So it is possible.

            Example 2:
            Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
            Output: false
            Explanation: There are a total of 2 courses to take.
            To take course 1 you should have finished course 0,
            and to take course 0 you should also have finished course 1. So it is impossible.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    /**
     * @brief Determines if all courses can be finished given the prerequisites.
     *
     * @param numCourses The total number of courses.
     * @param prerequisites A list of prerequisite pairs where each pair [a, b] indicates that course a depends on course b.
     * @return true if all courses can be finished, false otherwise.
     */
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // Create an adjacency list to represent the graph of course dependencies.
        vector<vector<int>> adj(numCourses);

        // Populate the adjacency list with the given prerequisites.
        for (auto it : prerequisites)
        {
            adj[it[0]].push_back(it[1]);
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
        // Add all courses with an in-degree of 0 to the queue
        // (i.e., courses with no prerequisites).
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

        // If the topological order contains all courses,
        // return true (i.e., all courses can be finished).
        if (topo.size() == numCourses)
        {
            return true;
        }
        // Otherwise, return false
        // (i.e., there is a cycle in the graph, and not all courses can be finished).
        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    int numCourses = 4;
    bool result = sol.canFinish(numCourses, prerequisites);
    cout << (result ? "All courses can be finished." : "Not all courses can be finished.") << endl;

    return 0;
}