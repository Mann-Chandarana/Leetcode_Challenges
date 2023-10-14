/*-------- Medium -----------*/

/*- Maximum Product of Splitted Binary Tree  -*/

//////// Question number 1339.

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
long long tree_sum = 0, max_prod = 1, modulo = (1e9 + 7);

void total_sum(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    tree_sum += root->val;
    total_sum(root->left);
    total_sum(root->right);
}

long long subtree_pro(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    long long l = subtree_pro(root->left);
    long long r = subtree_pro(root->right);
    long long subtree_sum = l + r + root->val;
    max_prod = max(max_prod, (tree_sum - subtree_sum) * subtree_sum);
    return subtree_sum;
}

int maxProduct(TreeNode *root)
{
    total_sum(root);
    subtree_pro(root);

    return (int)(max_prod % modulo);
}

int main()
{
    return 0;
}