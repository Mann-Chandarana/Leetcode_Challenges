/*-------- Medium -----------*/

/*- Construct Binary Search Tree from Preorder Traversal -*/

//////// Question number 1008.

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

TreeNode *func(vector<int> preorder, int mini, int maxi, int &index)
{
    if (index >= preorder.size())
        return NULL;

    if (preorder[index] < mini || preorder[index] > maxi)
        return NULL;

    TreeNode *root = new TreeNode(preorder[index++]);

    root->left = func(preorder, mini, root->val, index);
    root->right = func(preorder, root->val, maxi, index);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int index = 0;
    // return func(preorder, INT_MIN, INT_MAX, index);
    return func(preorder, INT_MAX, index);
}

/* Using only one INT_MAX */

TreeNode *func(vector<int> preorder, int bound, int i)
{
    if (i == preorder.size() or preorder[i] > bound)
        return NULL;

    TreeNode *root = new TreeNode(preorder[i++]);

    root->left = func(preorder, root->val, i);
    root->right = func(preorder, bound, i);

    return root;
}

int main()
{
    return 0;
}