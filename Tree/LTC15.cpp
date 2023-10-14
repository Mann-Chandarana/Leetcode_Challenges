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

bool isCompleteTree(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    bool nullSoFar = false;

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        if (temp == NULL)
            nullSoFar = true;
        else
        {
            if (nullSoFar)
                return false;

            q.push(temp->left);
            q.push(temp->right);
        }
    }

    return true;
}

/** Using DFS **/

int countNode(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + countNode(root->left) + countNode(root->right);
}

bool dfs(TreeNode *root, int idx, int total)
{
    if (root == NULL)
        return true;

    if (idx > total)
        return false;

    return dfs(root->left, 2 * idx, total) && dfs(root->right, 2 * idx + 1, total);
}

bool isCompleteTree(TreeNode *root)
{
    int total_no = countNode(root);
    return dfs(root, 1, total_no);
}

int main()
{
    return 0;
}