/**
 *  @file: 731_My_Calendar_II.cpp
 *  @author: Avinash Yadav
 *  @date: 04-06-2025
 *  @link: https://leetcode.com/problems/my-calendar-ii/description/
 *  @brief:
 */

#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo
{
public:
    map<int, int> stops;

    MyCalendarTwo()
    {
    }

    bool book(int startTime, int endTime)
    {
        stops[startTime]++;
        stops[endTime]--;

        int booked = 0;

        for (auto &stop : stops)
        {
            booked += stop.second;

            if (booked > 2)
            {
                stops[startTime]--;
                stops[endTime]++;

                if (stops[startTime] == 0)
                {
                    stops.erase(startTime);
                }
                if (stops[endTime] == 0)
                {
                    stops.erase(endTime);
                }

                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */