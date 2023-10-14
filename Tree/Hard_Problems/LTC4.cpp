/*-------- Medium -----------*/

/*- All Nodes Distance K in Binary Tree  -*/

//////// Question number 863.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findParent(unordered_map<TreeNode *, TreeNode *> &mp, TreeNode *root)
{
    if (root == NULL)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        if (temp->left)
        {
            mp[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            mp[temp->right] = temp;
            q.push(temp->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    vector<int> answer;
    unordered_map<TreeNode *, TreeNode *> node_to_parent;
    unordered_map<TreeNode *, bool> visited;
    node_to_parent[root] = NULL;
    findParent(node_to_parent, root);

    queue<pair<TreeNode *, int>> q;
    q.push({target, 0});
    visited[target] = true;

    while (!q.empty())
    {
        pair<TreeNode *, int> temp = q.front();
        q.pop();

        if (temp.second == k)
        {
            answer.push_back(temp.first->val);
            continue;
        }

        if (!visited[temp.first->left] and temp.first->left)
        {
            visited[temp.first->left] = true;
            q.push({temp.first->left, temp.second + 1});
        }
        if (!visited[temp.first->right] and temp.first->right)
        {
            visited[temp.first->right] = true;
            q.push({temp.first->right, temp.second + 1});
        }
        if (!visited[node_to_parent[temp.first]] and node_to_parent[temp.first] != NULL)
        {
            visited[node_to_parent[temp.first]] = true;
            q.push({node_to_parent[temp.first], temp.second + 1});
        }
    }

    return answer;
}

int main()
{
    return 0;
}