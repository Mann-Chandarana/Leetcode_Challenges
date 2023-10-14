/* Easy  :- 104. Maximum Depth of Binary Tree */

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

/* Using Recursion */

int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left_height = maxDepth(root->left);
    int right_height = maxDepth(root->right);

    return 1 + max(left_height, right_height);
}

/* Using iterative dfs */

int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;

    while (!q.empty())
    {
        ++depth;
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            TreeNode *front = q.front();
            q.pop();

            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }
    return depth;
}

int main()
{
    return 0;
}