/*-------- Medium -----------*/

/*- Lowest Common Ancestor of a Binary Search Tree -*/

//////// Question number 235.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/****** Iterative Solution ******/

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while (root)
    {
        if (p->val < root->val && q->val < root->val)
            root = root->left;
        else if (p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root;
    }
    return root;
}

/****** Recursive Solution ******/

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;

    if (p->val < root->val and q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);

    if (p->val > root->val and q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);

    return root;
}

int main()
{
    return 0;
}