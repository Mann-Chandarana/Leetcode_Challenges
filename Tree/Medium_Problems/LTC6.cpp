/*-------- Medium -----------*/

/*- Binary Tree Zigzag Level Order Traversal  -*/

//////// Question number 103.

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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    queue<TreeNode *> q;
    q.push(root);
    bool lefttoright = true;

    while (!q.empty())
    {
        int n = q.size();
        vector<int> answer(n);

        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            int index = lefttoright ? i : n - i - 1;

            answer[index] = node->val;

            if (node->left)
            {
                q.push(node->left);
            }

            if (node->right)
            {
                q.push(node->right);
            }
        }
        lefttoright = !lefttoright;
        ans.push_back(answer);
    }

    return ans;
}

int main()
{
    return 0;
}