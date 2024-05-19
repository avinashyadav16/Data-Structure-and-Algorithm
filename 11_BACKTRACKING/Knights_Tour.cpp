/**
*  @file: Knights_Tour.cpp
*  @author: Avinash Yadav
*  @brief: The Knight's Tour problem is a classic algorithmic problem involving a knight on a chessboard.
           The knight must visit every square on the board exactly once. The problem can be solved using backtracking.
*  @date: 19-05-2024
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Define the size of the chessboard
#define N 8

// Possible moves of a knight
int moveX[] = {2, 1, -1, -2, -2, -1, 1, 2};
int moveY[] = {1, 2, 2, 1, -1, -2, -2, -1};

// Utility function to check if (x, y) is valid board position
bool isValid(int x, int y, vector<vector<int>> &board)
{
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Utility function to print the solution
void printSolution(vector<vector<int>> &board)
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            cout << " " << setw(2) << board[x][y] << " ";
        }
        cout << endl;
    }
}

// Recursive utility function to solve Knight's Tour problem
bool solveKTUtil(int x, int y, int movei, vector<vector<int>> &board)
{
    int nextX, nextY;
    if (movei == N * N)
        return true;

    // Try all next moves from the current coordinate x, y
    for (int k = 0; k < 8; k++)
    {
        nextX = x + moveX[k];
        nextY = y + moveY[k];
        if (isValid(nextX, nextY, board))
        {
            board[nextX][nextY] = movei;
            if (solveKTUtil(nextX, nextY, movei + 1, board))
                return true;
            else
                board[nextX][nextY] = -1; // backtrack
        }
    }

    return false;
}

// Function to solve the Knight's Tour problem using backtracking
bool solveKT()
{
    vector<vector<int>> board(N, vector<int>(N, -1));

    // Starting position of the knight
    board[0][0] = 0;

    if (!solveKTUtil(0, 0, 1, board))
    {
        cout << "Solution does not exist" << endl;
        return false;
    }
    else
    {
        printSolution(board);
    }

    return true;
}

int main()
{
    solveKT();
    return 0;
}