/*-------- Medium -----------*/

/*- Maximum Level Sum of a Binary Tree  -*/

//////// Question number 1161.

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

/* Using BFS */

int maxLevelSum(TreeNode *root)
{
    queue<TreeNode *> q;

    int maxi = INT_MIN, ans = 0, level = 0;
    q.push(root);

    while (!q.empty())
    {
        int sum = 0;
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            sum += temp->val;

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
        level++;
        if (sum > maxi)
        {
            maxi = sum;
            ans = level;
        }
    }
    return ans;
}

/* Using DFS */

map<int, int> mp;

void DFS(TreeNode *root, int currLevel)
{
    if (root == NULL)
        return;

    mp[currLevel] += root->val;

    DFS(root->left, currLevel + 1);
    DFS(root->right, currLevel + 1);
}

int maxLevelSum(TreeNode *root)
{
    DFS(root, 1);
    int maxSum = INT_MIN;
    int result = 0;

    for (auto element : mp)
    {
        int level = element.first;
        int value = element.second;

        if (value > maxSum)
        {
            maxSum = value;
            result = level;
        }
    }
    return result;
}

int main()
{
    return 0;
}