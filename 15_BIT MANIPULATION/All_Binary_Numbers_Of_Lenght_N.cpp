/**
*  @file: Generate_all_binary_strings.cpp
*  @author: Avinash Yadav
*  @date: 10-06-2025
*  @link: https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1
*  @brief: Given an integer N , Print all binary strings of size N which do not contain consecutive 1s.
            A binary string is that string which contains only 0 and 1.

            Example 1:
            Input: N = 3
            Output: 000 , 001 , 010 , 100 , 101
            Explanation:
                None of the above strings contain consecutive 1s. "110" is not an answer as it has '1's occuring consecutively.

            Your Task:
                You don't need to read input or print anything. Your task is to complete the function generateBinaryStrings() which takes an integer N as input and returns a list of all valid binary strings in lexicographically increasing order.

            Expected Time Complexity: O(2N)
            Expected Auxiliary Space: O(N)

            Constraints: 1 <= N <= 20
*/

#include <bits/stdc++.h>
using namespace std;

// Function to generate all binary strings of size N without consecutive 1s
class Solution
{
public:
    // Helper function to recursively build binary strings
    // idx: current position in the string
    // num: total length of the string
    // str: current string being built
    // res: vector to store all valid strings
    void generateStr(int idx, int &num, string str, vector<string> &res)
    {
        // Base case:
        // if the current string has reached the required length
        if (idx == num)
        {
            // Add the valid string to the result
            res.push_back(str);

            return;
        }

        // If the last character is not '1',
        // we can add both '0' and '1'
        if (str.empty() || str.back() != '1')
        {
            // Add '0' at current position
            generateStr(idx + 1, num, str + "0", res);

            // Add '1' at current position
            generateStr(idx + 1, num, str + "1", res);
        }
        else
        {
            // If the last character is '1',
            // we can only add '0' to avoid consecutive '1's
            generateStr(idx + 1, num, str + "0", res);
        }
    }

    // Function to generate all valid binary strings
    vector<string> generateBinaryStrings(int num)
    {
        // To store the result
        vector<string> res;

        // Start with an empty string
        string str = "";

        // Start recursion from index 0
        generateStr(0, num, str, res);

        return res;
    }
};

int main()
{
    int num;
    cin >> num;

    Solution sol;

    vector<string> result = sol.generateBinaryStrings(num);

    for (auto &st : result)
    {
        cout << st << " ";
    }

    return 0;
}