/*-------- Hard -----------*/

/*- Vertical Order Traversal of a Binary Tree  -*/

//////// Question number 987.

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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    if (root == NULL)
        return {};

    vector<vector<int>> ans;

    map<int, map<int, multiset<int>>> m; // {vertical axis, {level axis, Node_Values}}

    queue<pair<TreeNode *, pair<int, int>>> q; // {root, {vertical axis, level axis}}

    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        TreeNode *node = it.first;

        int x = it.second.first;  // level axis
        int y = it.second.second; // vertical axis

        m[x][y].insert(node->val);

        if (node->left)
            q.push({node->left, {x - 1, y + 1}});

        if (node->right)
            q.push({node->right, {x + 1, y + 1}});
    }
    for (auto it : m)
    {
        vector<int> temp;

        for (auto i : it.second)
            temp.insert(temp.end(), i.second.begin(), i.second.end());

        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    return 0;
}