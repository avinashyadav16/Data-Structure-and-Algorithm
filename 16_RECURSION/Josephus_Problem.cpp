/**
*  @file: Josephus_Problem.cpp
*  @author: Avinash Yadav
*  @date: 02-06-2025
*  @link: https://www.geeksforgeeks.org/problems/josephus-problem/1
*  @brief: A total of n people are standing in a circle, and you are one of them playing a game.
            Starting from a person, k persons will be counted in order along the circle, and the kth person will be killed.
            Then the next k persons will be counted along the circle, and again the kth person will be killed.
            This cycle will continue until only a single person is left in the circle.

            If there are 5 people in the circle in the order A, B, C, D, and E, you will choose k=3.
            Starting from A, you will count A, B and C. C will be the 3rd person and will be killed.
            Then you will continue counting from D, E and then A. A will be third person and will be killed.

            You will be given an array where the first element is the first person from whom the counting will start and
            the subsequent order of the people. You want to be the last one standing.
            Determine the index at which you should stand to survive the game. Return an integer denoting safe position.
*/

#include <bits/stdc++.h>
using namespace std;

// METHOD 01
class Solution
{
public:
    int josephus(int n, int k)
    {
        if (n == 1)
        {
            return 1;
        }

        return (((josephus(n - 1, k) + (k - 1)) % n) + 1);
    }
};

// METHOD 02: Solving Josephus problem using List
void Josh(vector<int> person, int k, int index)
{
    // Base case , when only one person is left
    if (person.size() == 1)
    {
        cout << person[0] << endl;
        return;
    }

    // find the index of first person which will die
    index = ((index + k) % person.size());

    // remove the first person which is going to be killed
    person.erase(person.begin() + index);

    // recursive call for n-1 persons
    Josh(person, k, index);
}

int main()
{
    int n = 14; // specific n and k  values for originaljosephus problem

    int k = 2;
    k--; // (k-1)th person will be killed

    int index = 0; // The index where the person which will die

    vector<int> person;

    // fill the person vector
    for (int i = 1; i <= n; i++)
    {
        person.push_back(i);
    }

    Josh(person, k, index);
}

// [Approach - 2] Solving Josephus problem iteratively

int Josephus(int n, int k)
{
    k--;

    int arr[n];

    // Makes all the 'n' people alive by assigning them value = 1
    for (int i = 0; i < n; i++)
    {
        arr[i] = 1;
    }

    // Cut = 0 gives the sword to 1st person.
    int cnt = 0, cut = 0, num = 1;

    // Loop continues till n-1 person dies.
    while (cnt < (n - 1))
    {
        // Checks next (kth) alive persons.
        while (num <= k)
        {
            cut++;

            // Checks and resolves overflow of Index.
            cut = cut % n;

            if (arr[cut] == 1)
            {
                // Updates the number of persons alive.
                num++;
            }
        }

        // Refreshes value to 1 for next use.
        num = 1;

        // Kills the person at position of 'cut'
        arr[cut] = 0;

        // Updates the no. of killed persons.
        cnt++;

        cut++;

        // Checks and resolves overflow of Index.
        cut = cut % n;

        // Checks the next alive person the
        // sword is to be given.
        while (arr[cut] == 0)
        {
            cut++;

            // Checks and resolves overflow of Index.
            cut = cut % n;
        }
    }

    // Output is the position of the last man alive(Index + 1);
    return cut + 1;
}

int main()
{
    int n = 14, k = 2;
    cout << Josephus(n, k);
    return 0;
}