/*-------- Medium -----------*/

/*- Validate Binary Search Tree -*/

//////// Question number 98.

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

/* Using DFS */

long int num = LONG_MIN;

bool isValidBST(TreeNode *root)
{
    if (!root)
        return true;

    bool ans = isValidBST(root->left);

    if (root->val > num)
    {
        num = root->val;
    }
    else
        return false;

    return ans && isValidBST(root->right);
}

/* Using recursion */

bool isvalid(TreeNode *root, long maxi, long mini)
{
    if (root == NULL)
        return true;

    if (mini < root->val and maxi > root->val)
        return isvalid(root->left, root->val, mini) && isvalid(root->right, maxi, root->val);

    return false;
}

bool isValidBST(TreeNode *root)
{
    return isvalid(root, LONG_MAX, LONG_MIN);
}

int main()
{
    return 0;
}