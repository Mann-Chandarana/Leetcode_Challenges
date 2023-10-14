/*-------- Medium -----------*/

/*- Recover Binary Search Tree -*/

//////// Question number 99.

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

void inorder(TreeNode *root, TreeNode *first, TreeNode *sec, TreeNode *prev)
{
    if (root == NULL)
        return;
    inorder(root->left, first, sec, prev);
    if (prev && prev->val > root->val)
    {
        if (first == NULL)
            first = prev;
        sec = root;
    }
    prev = root;
    inorder(root->right, first, sec, prev);
}
void recoverTree(TreeNode *root)
{
    TreeNode *first = NULL;
    TreeNode *sec = NULL;
    TreeNode *prev = NULL;
    inorder(root, first, sec, prev);
    int t = first->val;
    first->val = sec->val;
    sec->val = t;
}

int main()
{
    return 0;
}