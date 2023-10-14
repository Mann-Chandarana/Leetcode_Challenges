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

/******** Recursive solution *********/

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);

    else
        return searchBST(root->right, val);
}

/******** Iterative solution *********/

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root->val == val)
        return root;

    TreeNode *temp = root;
    while (temp != NULL and temp->val != val)
    {
        if (val < temp->val)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (temp != NULL)
        return temp;
    else
        return NULL;
}

int main()
{
    return 0;
}