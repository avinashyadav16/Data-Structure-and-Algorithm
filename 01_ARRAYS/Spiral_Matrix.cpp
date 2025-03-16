#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    // Vector to store elements in spiral order
    vector<int> res;

    // Edge case: empty matrix
    if (matrix.empty())
        return res;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right)
    {
        // Step 1: Traverse from left to right along the top row
        for (int i = left; i <= right; i++)
            res.push_back(matrix[top][i]);

        // Move top boundary down
        top++;

        // Step 2: Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; i++)
            res.push_back(matrix[i][right]);

        // Move right boundary left
        right--;

        // Step 3: Traverse from right to left along the bottom row (if not already traversed)
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                res.push_back(matrix[bottom][i]);

            // Move bottom boundary up
            bottom--;
        }

        // Step 4: Traverse from bottom to top along the left column (if not already traversed)
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                res.push_back(matrix[i][left]);

            // Move left boundary right
            left++;
        }
    }

    // Final spiral order result
    return res;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral Order: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
