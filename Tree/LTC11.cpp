/* 783. Minimum Distance Between BST Nodes */

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

/*O(1) space */

void inorder(TreeNode *root, vector<int> &v)
{
    if (root->left != NULL)
        inorder(root->left, v);
    v.push_back(root->val);
    if (root->right != NULL)
        inorder(root->right, v);
    return;
}
int minDiffInBST(TreeNode *root)
{
    vector<int> v;
    inorder(root, v);
    int mini = INT_MAX;
    for (int i = 1; i < v.size(); i++)
    {
        mini = min(mini, v[i] - v[i - 1]);
    }
    return mini;
}

/* O(N) space */

int pred = -1;

void inorder(TreeNode *root, int& val)
{
    if (root == NULL)
        return;

    inorder(root->left, val);
    if (pred >= 0)
        val = min(root->val - pred, val);
    inorder(root->right, val);
}

int minDiffInBST(TreeNode *root)
{
    int val = INT_MAX;
    inorder(root,val);

    return val;
}

int main()
{
    return 0;
}