/* Boundary traversal */

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void left_boundary(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL and root->right == NULL))
        return;

    ans.push_back(root->data);
    if (root->left != NULL)
        left_boundary(root->left, ans);
    else
        left_boundary(root->right, ans);
}

void leaf_node(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left == NULL and root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    leaf_node(root->left, ans);
    leaf_node(root->right, ans);
}

void right_boundary(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL and root->right == NULL))
        return;

    if (root->right != NULL)
        right_boundary(root->right, ans);
    else
        right_boundary(root->left, ans);

    ans.push_back(root->data);
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    left_boundary(root->left, ans);

    leaf_node(root->left, ans);
    leaf_node(root->right, ans);

    right_boundary(root->right, ans);

    return ans;
}

int main()
{
    return 0;
}