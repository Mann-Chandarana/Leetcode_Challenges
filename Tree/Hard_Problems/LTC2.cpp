/*-------- Medium -----------*/

/*- Lowest Common Ancestor of a Binary Tree  -*/

//////// Question number 236.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;

    if (root->val == p->val || root->val == q->val)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL and right != NULL)
        return root;

    if (left != NULL and right == NULL)
        return left;

    if (right != NULL and left == NULL)
        return right;

    return NULL;
}

int main()
{
    return 0;
}