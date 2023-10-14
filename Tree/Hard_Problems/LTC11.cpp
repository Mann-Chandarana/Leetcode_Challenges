/* Morris Traversal */

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

/* Inorder Traversal */
/* Space complexity :- O(N), Time complexity :- O(1) */

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;
            while (prev->right != NULL and prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

/* Preorder Traversal */
/* Space complexity :- O(N), Time complexity :- O(1) */

vector<int> PreorderTraversal(TreeNode *root)
{
    vector<int> preorder;
    TreeNode *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            preorder.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;
            while (prev->right != NULL and prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                preorder.push_back(curr->val);
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}

int main()
{
    return 0;
}