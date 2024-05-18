/**
 *  @file: Matrix_Chain_Multiplication.cpp
 *  @author: Avinash Yadav
 *  @brief: Matrix Chain Multiplication Using DP
 *  @date: 19-05-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Function to perform Matrix Chain Multiplication
int matrixChainOrder(const vector<int> &p)
{
    // Number of matrices (size of p is number of matrices + 1)
    int n = p.size() - 1; 
    
    // DP table to store the minimum cost of matrix multiplications
    vector<vector<int>> m(n, vector<int>(n, 0));

    // l is chain length, start from 2 to n (length of subchains)
    for (int l = 2; l <= n; l++)
    {
        // i is the starting index of the chain
        for (int i = 0; i <= n - l; i++)
        {
            // j is the ending index of the chain
            int j = i + l - 1;
            
            // Initialize m[i][j] to a large value (infinity) to find the minimum
            m[i][j] = INT_MAX;
            
            // Try placing the parenthesis at different places between i and j
            for (int k = i; k < j; k++)
            {
                // Calculate the cost of multiplying the matrices from Ai to Ak and from Ak+1 to Aj
                int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                
                // If this cost is less than the current cost, update m[i][j]
                if (q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }

    // Return the minimum number of multiplications needed to multiply the entire chain
    return m[0][n - 1];
}

int main()
{
    // Dimensions of the matrices
    // Matrices        A1, A2, A3, A4, A5, A6
    vector<int> p = {30, 35, 15, 5, 10, 20, 25};

    // Output the minimum number of multiplications
    cout << "Minimum number of multiplications is " << matrixChainOrder(p) << endl;

    return 0;
}