/**
 *  @file: ChessKnight.cpp
 *  @author: Avinash Yadav   | AP22110010366
 *  @brief: 2. Given a N*N board with the knight placed on the first block of an empty board
                moving according to the rules of chess knight must visit each square exactly once.
                Print the order of each cell in which they are visited.
 *  @date: 26-04-2024
 */

#include <bits/stdc++.h>
using namespace std;

// Size of the chessboard
int N;

// Chessboard to track visited cells
vector<vector<int>> board;

// Possible x-axis moves for the knight
int moveX[] = {2, 1, -1, -2, -2, -1, 1, 2};

// Possible y-axis moves for the knight
int moveY[] = {1, 2, 2, 1, -1, -2, -2, -1};

// Function to check if a move is valid
bool isValidMove(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Recursive function to explore knight's moves
bool exploreKnightMoves(int x, int y, int moveCount)
{
    if (moveCount == N * N) // All cells visited
        return true;

    for (int i = 0; i < 8; ++i)
    {
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];
        if (isValidMove(nextX, nextY))
        {
            board[nextX][nextY] = moveCount;
            if (exploreKnightMoves(nextX, nextY, moveCount + 1))
                return true;
            board[nextX][nextY] = -1; // Backtrack
        }
    }
    return false;
}

// Function to print the order of visited cells
void printVisitedOrder()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << setw(3) << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Enter the size of the chessboard (N*N): ";
    cin >> N;

    // Initialize the chessboard
    board.resize(N, vector<int>(N, -1));
    board[0][0] = 0; // Start from the first block

    if (exploreKnightMoves(0, 0, 1))
    {
        cout << "Order of visited cells:" << endl;
        printVisitedOrder();
    }
    else
    {
        cout << "Knight cannot visit each square exactly once." << endl;
    }

    return 0;
}