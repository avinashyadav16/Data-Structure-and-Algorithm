/**
*  @file: 155_Min_Stack.cpp
*  @author: Avinash Yadav
*  @date: 10-08-2025
*  @link: https://leetcode.com/problems/min-stack/description/
*  @brief: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
            Implement the MinStack class:
                MinStack() initializes the stack object.
                void push(int val) pushes the element val onto the stack.
                void pop() removes the element on the top of the stack.
                int top() gets the top element of the stack.
                int getMin() retrieves the minimum element in the stack.

            You must implement a solution with O(1) time complexity for each function.

            Example 1:

            Input
                ["MinStack","push","push","push","getMin","pop","top","getMin"]
                [[],[-2],[0],[-3],[],[],[],[]]

                Output
                [null,null,null,null,-3,null,0,-2]

                Explanation
                MinStack minStack = new MinStack();
                minStack.push(-2);
                minStack.push(0);
                minStack.push(-3);
                minStack.getMin(); // return -3
                minStack.pop();
                minStack.top();    // return 0
                minStack.getMin(); // return -2

*/

#include <bits/stdc++.h>
using namespace std;

// METHOD - 01
// TC = O(1)
// SC = O(2N)
class MinStack1
{
public:
    stack<pair<int, int>> st;

    MinStack1() {}

    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            st.push({val, min(val, st.top().second)});
        }
    }

    void pop()
    {
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

// METHOD - 02
// TC = O(1)
// SC = O(N)
class MinStack2
{
public:
    stack<long long> st;
    long long mini = LLONG_MAX;

    MinStack2() {}

    void push(int val)
    {
        long long value = val;
        if (st.empty())
        {
            mini = value;
            st.push(value);
        }
        else
        {
            if (value > mini)
            {
                st.push(value);
            }
            else
            {
                st.push(2LL * value - mini);
                mini = value;
            }
        }
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }

        long long removedTop = st.top();
        st.pop();
        if (removedTop < mini)
        {
            mini = 2LL * mini - removedTop;
        }
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        else if (mini < st.top())
        {
            return (int)st.top();
        }
        else
        {
            return (int)mini;
        }
    }

    int getMin()
    {
        return (int)mini;
    }
};

// METHOD - 03
class MinStack3
{
    stack<int> st;

    stack<int> minSt;

public:
    MinStack3() {}

    void push(int val)
    {
        st.push(val);

        if (minSt.empty() || val <= minSt.top())
        {
            minSt.push(val);
        }
        else
        {
            minSt.push(minSt.top());
        }
    }

    void pop()
    {
        st.pop();

        minSt.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minSt.top();
    }
};

int main()
{
    // METHOD - 01
    MinStack1 minStack1;
    minStack1.push(-2);
    minStack1.push(0);
    minStack1.push(-3);
    cout << minStack1.getMin() << endl;
    minStack1.pop();
    cout << minStack1.top() << endl;
    cout << minStack1.getMin() << endl;

    // METHOD - 02
    MinStack2 minStack2;
    minStack2.push(-2);
    minStack2.push(0);
    minStack2.push(-3);
    cout << minStack2.getMin() << endl;
    minStack2.pop();
    cout << minStack2.top() << endl;
    cout << minStack2.getMin() << endl;

    // METHOD - 03
    MinStack3 minStack3;
    minStack3.push(-2);
    minStack3.push(0);
    minStack3.push(-3);
    cout << minStack3.getMin() << endl;
    minStack3.pop();
    cout << minStack3.top() << endl;
    cout << minStack3.getMin() << endl;

    return 0;
}
