/* 226. Invert Binary Tree */

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

/* Efficient space complexity */

TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
        return root;

    /** Swapping left and right **/

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    root->left = invertTree(root->left);
    root->right = invertTree(root->right);

    return root;
}

/* Efficient time complexity */

TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
        return root;

    TreeNode *left = root->left;
    TreeNode *right = root->right;

    root->left = invertTree(right);
    root->right = invertTree(left);

    return root;
}

int main()
{
    return 0;
}