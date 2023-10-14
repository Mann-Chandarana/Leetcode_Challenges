// Geeks for Geeks :- Root to Leaf Paths

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void solve(vector<vector<int>> &ans, Node *root, vector<int> answer)
{
    if (root->left == NULL and root->right == NULL)
    {
        answer.push_back(root->data);
        ans.push_back(answer);
        return;
    }
    answer.push_back(root->data);
    if (root->left)
        solve(ans, root->left, answer);

    if (root->right)
        solve(ans, root->right, answer);
}

vector<vector<int>> Paths(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    vector<int> answer;
    solve(ans, root, answer);
    return ans;
}

int main()
{
    return 0;
}