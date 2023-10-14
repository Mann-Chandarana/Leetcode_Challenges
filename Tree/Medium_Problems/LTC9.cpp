/* Easy :- 101. Symmetric Tree */

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

bool isSymmetricUtil(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL and root2 == NULL)
        return true;

    return ((root1->val==root2->val) and isSymmetricUtil(root1->left,root2->right) and isSymmetricUtil(root1->right,root2->left));
}

bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    return isSymmetricUtil(root->left, root->right);
}

int main()
{
    return 0;
}