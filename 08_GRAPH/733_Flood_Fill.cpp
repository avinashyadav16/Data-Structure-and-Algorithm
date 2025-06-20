/**
*  @file: 733_Flood_Fill.cpp
*  @author: Avinash Yadav
*  @date: 18-06-2025
*  @link: https://leetcode.com/problems/flood-fill/description/
*  @link: https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
*  @brief: You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image.
            You are also given three integers sr, sc, and color.
            Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
            To perform a flood fill:
            Begin with the starting pixel and change its color to color.
            Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel,
            either horizontally or vertically) and shares the same color as the starting pixel.
            Keep repeating this process by checking neighboring pixels of the updated pixels and
            modifying their color if it matches the original color of the starting pixel.
            The process stops when there are no more adjacent pixels of the original color to update.
            Return the modified image after performing the flood fill.

            Example 1:
                Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
                Output: [[2,2,2],[2,2,0],[2,0,1]]
                Explanation:
                From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel),
                all pixels connected by a path of the same color as the starting pixel
                (i.e., the blue pixels) are colored with the new color.
                Note the bottom corner is not colored 2,
                because it is not horizontally or vertically connected to the starting pixel.

            Example 2:
                Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
                Output: [[0,0,0],[0,0,0]]
                Explanation:
                The starting pixel is already colored with 0, which is the same as the target color.
                Therefore, no changes are made to the image.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to perform DFS and fill the connected component
    void dfs(int row, int col,
             int initialColor, int &color,
             vector<vector<int>> &image,
             vector<vector<int>> &ans,
             vector<int> &dr, vector<int> &dc)
    {
        // Change the color of the current pixel
        ans[row][col] = color;

        int m = image.size();
        int n = image[0].size();

        // Explore all 4 directions (up, right, down, left)
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            // Check if the new position is within bounds,
            // has the initial color, and is not already colored
            if (newRow >= 0 && newRow < m &&
                newCol >= 0 && newCol < n &&
                image[newRow][newCol] == initialColor &&
                ans[newRow][newCol] != color)
            {
                // Recursively fill the connected pixel
                dfs(newRow, newCol,
                    initialColor, color,
                    image, ans,
                    dr, dc);
            }
        }
    }

    // Main function to start the flood fill
    vector<vector<int>> floodFill(vector<vector<int>> &image,
                                  int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();

        // Copy the original image to store the result
        vector<vector<int>> ans = image;

        int initialColor = image[sr][sc];

        // If the starting pixel is already the target color,
        // no need to proceed
        if (initialColor == color)
            return ans;

        // Direction vectors for 4-connected neighbors
        vector<int> dr = {-1, 0, +1, 0};
        vector<int> dc = {0, +1, 0, -1};

        // Start DFS from the given starting pixel
        dfs(sr, sc, initialColor, color, image, ans, dr, dc);

        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////////////
// DRIVER CODE:
//////////////////////////////////////////////////////////////////////////////////
int main()
{
    vector<vector<int>> image1 = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}; // Output: [[2,2,2],[2,2,0],[2,0,1]]
    int sr1 = 1, sc1 = 1, color1 = 2;

    vector<vector<int>> image2 = {{0, 0, 0}, {0, 0, 0}}; // Output: [[0,0,0],[0,0,0]]
    int sr2 = 0, sc2 = 0, color2 = 0;

    auto printImage = [](const vector<vector<int>> &img)
    {
        for (const auto &row : img)
        {
            for (int val : row)
                cout << val << " ";
            cout << endl;
        }

        cout << endl;
    };

    cout << "OUTPUT IS: " << endl;
    Solution sol1;
    printImage(sol1.floodFill(image1, sr1, sc1, color1));
    printImage(sol1.floodFill(image2, sr2, sc2, color2));

    return 0;
}