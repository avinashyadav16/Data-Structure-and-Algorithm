/**
*  @file: Infix_To_Postfix.cpp
*  @author: Avinash Yadav
*  @date: 06-06-2025
*  @link: https://www.codechef.com/problems/ONP
*  @brief: Reverse Polish Notation (RPN) is a mathematical notation where every operator follows all of its operands.
            For instance, to add three and four, one would write "3 4 +" rather than "3 + 4".
            If there are multiple operations, the operator is given immediately after its second operand;
            so the expression written "3 − 4 + 5" would be written "3 4 − 5 +" first subtract 4 from 3, then add 5 to that.
            Transform the algebraic expression with brackets into RPN form.

            You can assume that for the test cases below only single letters will be used,
            brackets [] will not be used and each expression has only one RPN form (no expressions like a*b*c)
*/

#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int pre(char ch)
{
    if (ch == '^')
    {
        return 3; // Highest precedence for '^'
    }
    else if (ch == '/' || ch == '*')
    {
        return 2; // Next highest for '*' and '/'
    }
    else if (ch == '+' || ch == '-')
    {
        return 1; // Lowest for '+' and '-'
    }
    else
    {
        return -1; // For non-operators
    }
}

int main()
{
    int t;
    cin >> t; // Number of test cases

    while (t--)
    {
        string infix;
        cin >> infix; // Input infix expression

        int n = infix.size();

        string postfix; // Output postfix expression
        stack<char> st; // Stack to hold operators

        for (int i = 0; i < n; i++)
        {
            char ch = infix[i];

            // If operand, add to postfix
            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
            {
                postfix += ch;
            }
            // If '(', push to stack
            else if (ch == '(')
            {
                st.push('(');
            }
            // If ')', pop and output from the stack until '(' is found
            else if (ch == ')')
            {
                while (st.top() != '(')
                {
                    postfix += st.top();
                    st.pop();
                }
                st.pop(); // Remove '(' from stack
            }
            // If operator, pop operators from stack with higher or equal precedence and push current operator
            else
            {
                while (!st.empty() && pre(ch) <= pre(st.top()))
                {
                    postfix += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        // Pop all remaining operators from the stack
        while (!st.empty())
        {
            postfix += st.top();
            st.pop();
        }

        // Output the postfix expression
        for (int i = 0; i < postfix.size(); i++)
        {
            cout << postfix[i];
        }

        cout << endl;
    }

    return 0;
}

// INPUT:
//  3
//  (a+(b*c))
//  ((a+b)*(z+x))
//  ((a+t)*((b+(a+c))^(c+d)))

// OUTPUT:
//  abc*+
//  ab+zx+*
//  at+bac++cd+^*