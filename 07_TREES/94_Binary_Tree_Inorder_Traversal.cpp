/**
*  @file: 94_Binary_Tree_Inorder_Traversal.cpp
*  @author: Avinash Yadav
*  @date: 06-06-2025
*  @link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
*  @brief: Given the root of a binary tree, return the inorder traversal of its nodes' values.

            Example 1:
                Input: root = [1,null,2,3]
                Output: [1,3,2]

            Example 2:
                Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
                Output: [4,2,6,5,7,1,3,9,8]

            Example 3:
                Input: root = []
                Output: []

            Example 4:
                Input: root = [1]
                Output: [1]

            Constraints:

                The number of nodes in the tree is in the range [0, 100].
                -100 <= Node.val <= 100

            Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include <bits/stdc++.h>
using namespace std;

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
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    // Method 01: Inorder Tree Traversal with Recursion
    void recursionInorderTraversal(TreeNode *root, vector<int> &result)
    {
        if (!root)
        {
            return;
        }
        recursionInorderTraversal(root->left, result);
        result.push_back(root->val);
        recursionInorderTraversal(root->right, result);
    }

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    // [Naive Approach] Using Stack - O(n) Time and O(h) Space

    void stackInorderTraversal(TreeNode *root, vector<int> &result)
    {
        stack<TreeNode *> st;

        TreeNode *curr = root;

        // Reach the left most Node of the curr Node
        while (curr != nullptr || !st.empty())
        {
            while (curr != nullptr)
            {
                // Place pointer to a tree node on the stack before traversing
                // the node's left subtree
                st.push(curr);

                curr = curr->left;
            }

            // Current must be NULL at this point
            curr = st.top();
            st.pop();

            result.push_back(curr->val);

            // we have visited the node and its left subtree.
            // Now, it's right subtree's turn
            curr = curr->right;
        }
    }

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    // Main Function For The Inorder Traversal:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;

        if (!root)
        {
            return result;
        }

        // recursionInorderTraversal(root, result);
        stackInorderTraversal(root, result);

        return result;
    }
};

int main()
{
    // Construct the tree: [1,null,2,3] => [1,3,2]
    TreeNode *root1 = new TreeNode(1);

    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(3);

    // Construct the tree: [1,2,3,4,5,null,8,null,null,6,7,9] => [4,2,6,5,7,1,3,9,8]
    TreeNode *root2 = new TreeNode(1);

    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);

    root2->right->right = new TreeNode(8);

    root2->left->right->left = new TreeNode(6);
    root2->left->right->right = new TreeNode(7);

    root2->right->right->left = new TreeNode(9);

    Solution sol;

    vector<int> result1 = sol.inorderTraversal(root1);
    vector<int> result2 = sol.inorderTraversal(root2);

    auto printResult = [](const vector<int> &res)
    {
        cout << "[";

        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i];

            if (i < res.size() - 1)
                cout << ",";
        }

        cout << "]" << endl;
    };

    printResult(result1);
    printResult(result2);

    return 0;
}