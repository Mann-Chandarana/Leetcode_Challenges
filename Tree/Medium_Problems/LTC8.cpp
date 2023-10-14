/*-------- Medium -----------*/

/*- Binary Tree Right Side View  -*/

//////// Question number 199.

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

/***** Using Recursion *****/

void createMapping(TreeNode *root, map<int, int> &mp, int y)
{
    if (root == NULL)
        return;

    mp[y] = root->val;
    createMapping(root->left, mp, y + 1);
    createMapping(root->right, mp, y + 1);
}

vector<int> rightSideView(TreeNode *root)
{
    map<int, int> mp;

    vector<int> ans;
    createMapping(root, mp, 0);

    for (auto element : mp)
    {
        ans.push_back(element.second);
    }

    return ans;
}

/***** Using Iteration *****/

vector<int> rightSideView(TreeNode *root)
{
    map<int, int> mp;

    vector<int> ans;

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        pair<TreeNode *, int> p = q.front();
        q.pop();

        TreeNode *temp = p.first;
        int y = p.second;

        mp[y] = temp->val;

        if (temp->left)
            q.push({temp->left, y + 1});

        if (temp->right)
            q.push({temp->right, y + 1});
    }
    for (auto element : mp)
    {
        ans.push_back(element.second);
    }

    return ans;
}

int main()
{
    return 0;
}