/* Easy :- 543. Diameter of Binary Tree */

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

/**** Using Pair ****/

pair<int, int> diameterFast(TreeNode *root)
{
    // base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));

    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameterOfBinaryTree(TreeNode *root)
{
    pair<int, int> answer = diameterFast(root);

    return answer.first;
}

/*** Using optimised appraoch ****/

int ans = 0;
int height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    ans = max(ans, 1 + lh + rh);
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode *root)
{
    height(root);
    return ans - 1;
}

int main()
{
    return 0;
}