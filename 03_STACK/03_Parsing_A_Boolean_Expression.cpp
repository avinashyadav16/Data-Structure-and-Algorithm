/**
*  @file: 03_Parsing_A_Boolean_Expression.cpp
*  @author: Avinash Yadav
*  @problem: 1106. Parsing A Boolean Expression [Leetcode]
*  @link: https://leetcode.com/problems/parsing-a-boolean-expression?envType=daily-question&envId=2024-10-20
*  @brief:
        A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:
            - 't' that evaluates to true.
            - 'f' that evaluates to false.
            - '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
            - '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
            - '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
        Given a string expression that represents a boolean expression, return the evaluation of that expression.

        It is guaranteed that the given expression is valid and follows the given rules.
        ---------------------------------------------------------------------------------------------------------------------------------------------------------------
        Example 1:
        Input: expression = "&(|(f))"
        Output: false
        Explanation:
        First, evaluate |(f) --> f. The expression is now "&(f)".
        Then, evaluate &(f) --> f. The expression is now "f".
        Finally, return false.

        Example 2:
        Input: expression = "|(f,f,f,t)"
        Output: true
        Explanation: The evaluation of (false OR false OR false OR true) is true.

        Example 3:
        Input: expression = "!(&(f,t))"
        Output: true
        Explanation:
        First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
        Then, evaluate !(f) --> NOT false --> true. We return true.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        stack<char> operators;
        stack<char> operands;

        for (int i = 0; i < expression.size(); i++)
        {
            if (
                expression[i] == '&' ||
                expression[i] == '|' ||
                expression[i] == '!' ||
                expression[i] == '(' ||
                expression[i] == 't' ||
                expression[i] == 'f')
            {
                operators.push(expression[i]);
            }

            if (expression[i] == ')')
            {
                while (operators.top() != '(')
                {
                    operands.push(operators.top());
                    operators.pop();
                }
                operators.pop();

                char operation = operators.top();
                operators.pop();

                bool result = (operands.top() == 't');
                operands.pop();

                if (operation == '!')
                {
                    result = !result;
                }
                else if (operation == '&')
                {
                    while (!operands.empty())
                    {
                        bool currentOperand = (operands.top() == 't');
                        result = result & currentOperand;
                        operands.pop();
                    }
                }
                else if (operation == '|')
                {
                    while (!operands.empty())
                    {
                        bool currentOperand = (operands.top() == 't');
                        result = result | currentOperand;
                        operands.pop();
                    }
                }

                operators.push(result ? 't' : 'f');
            }
        }

        return operators.top() == 't';
    }
};