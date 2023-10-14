/*-------- Medium -----------*/

/*- Insert into a Binary Search Tree -*/

//////// Question number 701.

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

/********* Using Recursion ************/

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return root;
    }

    if (val > root->val)
        root->right = insertIntoBST(root->right, val);

    else
        root->left = insertIntoBST(root->left, val);

    return root;
}

/********* Using Iteration ************/

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
        return new TreeNode(val);
    TreeNode *curr = root;
    TreeNode *prev = NULL;
    while (curr)
    {
        prev = curr;
        if (curr->val < val)
            curr = curr->right;
        else
            curr = curr->left;
    }
    if (prev->val < val)
    {
        prev->right = new TreeNode(val);
    }
    else
        prev->left = new TreeNode(val);
    return root;
}

int main()
{
    return 0;
}