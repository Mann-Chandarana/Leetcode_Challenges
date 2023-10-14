/*-------- Medium -----------*/

/*- Delete Node in a BST -*/

//////// Question number 450.

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

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return root;

    if (root->val == key)
    {
        // 0 children
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 children
        if (root->left != NULL and root->right == NULL)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        if (root->right != NULL and root->left == NULL)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }

        // 2 Children

        if (root->right != NULL and root->left != NULL)
        {
            TreeNode *temp = root->left;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            root->val = temp->val;
            root->left = deleteNode(root->left, temp->val);
        }
    }
    else if (root->val < key)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }

    else
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    return root;
}

int main()
{
    return 0;
}