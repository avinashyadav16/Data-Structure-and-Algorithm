/**
 *  @file: Task_Scheduling.cpp
 *  @author: Avinash Yadav
 *  @brief: Provide the implementation of the problem Task Scheduling problem (greedy algorithm).
 *  @date: 22-03-2024
 */

#include <bits/stdc++.h>
using namespace std;

// Defining the Task structure to store the information about each task:
struct Task
{
    int taskNum;  // Task number
    int deadline; // Deadline by which the task needs to be completed.
    int profit;   // Profit associated with completing the task.
};

// Comparator function to sort tasks based on their deadlines:
bool compareTasks(Task t1, Task t2)
{
    // Compares and return two tasks based on their deadlines.
    return t1.deadline < t2.deadline;
}

void scheduleTasks(vector<Task> &tasks)
{
    // Sort tasks based on deadlines:
    sort(tasks.begin(), tasks.end(), compareTasks); // Sorts the tasks using the compareTasks function.

    int n = tasks.size();        // Number of tasks.
    vector<bool> slot(n, false); // Array to track whether a slot is occupied.
    int totalProfit = 0;         // Total profit earned by completing tasks.
    int totalTasksScheduled = 0; // Total number of tasks scheduled within their deadlines.

    // Iterate through each task:
    for (int i = 0; i < n; ++i)
    {
        // Find a free slot before the deadline:
        // Loop through available slots before the task deadline.
        for (int j = min(n, tasks[i].deadline) - 1; j >= 0; --j)
        {
            // If the slot is not occupied.
            if (!slot[j])
            {
                slot[j] = true;                 // Mark the slot as occupied.
                totalProfit += tasks[i].profit; // Add the profit of the current task to total profit.
                totalTasksScheduled++;          // Increment the count of tasks scheduled.
                break;                          // Break the loop since the task is scheduled.
            }
        }
    }

    // Output the total profit earned and total tasks scheduled:
    cout << "Total profit: " << totalProfit << endl;
    cout << "Total tasks scheduled: " << totalTasksScheduled << endl;
}

int main()
{
    // Defining tasks with their task numbers, deadlines, and profits:
    vector<Task> tasks = {
        {1, 2, 30},
        {2, 1, 20},
        {3, 2, 10},
        {4, 3, 50},
        {5, 1, 40}};

    // Calling the scheduleTasks function to schedule tasks and calculate total profit:
    scheduleTasks(tasks);

    return 0;
}
