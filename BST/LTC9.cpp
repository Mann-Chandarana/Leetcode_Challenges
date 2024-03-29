/*-------- Medium -----------*/

/*- Kth Smallest Element in a BST -*/

//////// Question number 230.

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

int kthSmallest(TreeNode *root, int k)
{
    if (root == NULL)
        return -1;

    int left = kthSmallest(root->left, k);

    if (left != -1)
        return left;
    k--;

    if (k == 0)
        return root->val;

    return kthSmallest(root->right, k);
}

int main()
{
    return 0;
}