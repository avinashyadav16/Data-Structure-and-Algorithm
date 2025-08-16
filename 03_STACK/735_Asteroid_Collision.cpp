/**
*  @file: 735_Asteroid_Collision.cpp
*  @author: Avinash Yadav
*  @date: 14-08-2025
*  @link: https://leetcode.com/problems/asteroid-collision/description/
*  @brief: We are given an array asteroids of integers representing asteroids in a row.
            The indices of the asteriod in the array represent their relative position in space.

            For each asteroid, the absolute value represents its size,
            and the sign represents its direction (positive meaning right, negative meaning left).
            Each asteroid moves at the same speed.

            Find out the state of the asteroids after all collisions.
            If two asteroids meet, the smaller one will explode.
            If both are the same size, both will explode.
            Two asteroids moving in the same direction will never meet.

            Example 1:
                Input: asteroids = [5,10,-5]
                Output: [5,10]
                Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

            Example 2:
                Input: asteroids = [8,-8]
                Output: []
                Explanation: The 8 and -8 collide exploding each other.

            Example 3:
                Input: asteroids = [10,2,-5]
                Output: [10]
                Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();

        // 'ls' acts as a stack
        // to keep track of surviving asteroids
        vector<int> ls;

        for (int i = 0; i < n; i++)
        {
            // If the asteroid is moving right,
            // just add it to the stack
            if (asteroids[i] > 0)
            {
                ls.push_back(asteroids[i]);
            }
            else
            {
                // The asteroid is moving left,
                // so check for collisions
                // Pop smaller right-moving asteroids
                // from the stack
                while (!ls.empty() &&
                       ls.back() > 0 &&
                       ls.back() < abs(asteroids[i]))
                {
                    // Right-moving asteroid explodes
                    ls.pop_back();
                }

                // If the top of the stack is
                // a right-moving asteroid of the same size,
                // both explode
                if (!ls.empty() &&
                    ls.back() == abs(asteroids[i]))
                {
                    // Both asteroids explode
                    ls.pop_back();
                }
                // If the stack is empty or
                // the top is a left-moving asteroid,
                // push the current one
                else if (ls.empty() || ls.back() < 0)
                {
                    ls.push_back(asteroids[i]);
                }
            }
        }

        // Return the surviving asteroids
        return ls;
    }
};
