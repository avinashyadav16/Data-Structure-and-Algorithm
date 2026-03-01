/**
 *  @file: 102_Binary_Tree_Level_Order_Traversal.cpp
 *  @author: Avinash Yadav
 *  @date: 06-06-2025
 *  @link: https://leetcode.com/problems/binary-tree-level-order-traversal/
 *  @brief: Given the root of a binary tree, return the level order traversal of its nodes' values.
 *           (i.e., from left to right, level by level).
            Example 1:
                Input: root = [3,9,20,null,null,15,7]
                Output: [[3],[9,20],[15,7]]

            Example 2:
                Input: root = [1]
                Output: [[1]]

            Example 3:
                Input: root = []
                Output: []
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;

        if (!root)
        {
            return result;
        }

        deque<TreeNode *> dq;
        dq.push_back(root);

        while (!dq.empty())
        {
            int dqLen = dq.size();

            vector<int> level;

            for (int i = 0; i < dqLen; i++)
            {
                TreeNode *curr = dq.front();
                dq.pop_front();

                level.push_back(curr->val);

                if (curr->left)
                {
                    dq.push_back(curr->left);
                }
                if (curr->right)
                {
                    dq.push_back(curr->right);
                }
            }

            result.push_back(level);
        }

        return result;
    }
};

int main()
{
    // Construct the tree: [3,9,20,null,null,15,7] => [[3],[9,20],[15,7]]
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    // Construct the tree: [1] => [[1]]
    TreeNode *root2 = new TreeNode(1);

    // Construct the tree: [] => []
    TreeNode *root3 = nullptr;

    Solution sol;
    vector<vector<int>> result1 = sol.levelOrder(root1);
    vector<vector<int>> result2 = sol.levelOrder(root2);
    vector<vector<int>> result3 = sol.levelOrder(root3);

    auto printResult = [](const vector<vector<int>> &result)
    {
        cout << "[";
        for (size_t i = 0; i < result.size(); ++i)
        {
            cout << "[";
            for (size_t j = 0; j < result[i].size(); ++j)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << ",";
            }
            cout << "]";
            if (i < result.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    };

    printResult(result1);
    printResult(result2);
    printResult(result3);

    return 0;
}