/*-------- Medium -----------*/

/*- Maximum difference between node and ancestors  -*/

//////// Question number 1026.

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

void Diff(TreeNode *root, int mini, int maxi, int &diff)
{
    if (root == NULL)
    {
        return;
    }
    maxi = max(maxi, root->val);
    mini = min(mini, root->val);

    if (root->left == NULL and root->right == NULL)
    {
        diff = max(diff, abs(maxi - mini));
        return;
    }

    if (root->left != NULL)
    {
        Diff(root->left, mini, maxi, diff);
    }
    if (root->right != NULL)
    {
        Diff(root->right, mini, maxi, diff);
    }
}

int maxAncestorDiff(TreeNode *root)
{
    int diff = INT_MIN;
    Diff(root, INT_MAX, INT_MIN, diff);
    return diff;
}

int main()
{

    return 0;
}