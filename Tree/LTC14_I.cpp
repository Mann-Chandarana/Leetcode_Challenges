/*-------- Hard -----------*/

/*- Sum Root to Leaf Numbers  -*/

//////// Question number 129.

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

/* Recursive */

int sum(TreeNode *root, int curr)
{
    if (root == NULL)
        return 0;

    curr = curr * 10 + root->val;
    if (root->left == NULL and root->right == NULL)
        return curr;

    int leftsum = sum(root->left, curr);
    int rightsum = sum(root->right, curr);

    return leftsum + rightsum;
}

int sumNumbers(TreeNode *root)
{
    int curr_sum = 0;
    return sum(root, curr_sum);
}

/* Iterative */

int sumNumbers(TreeNode *root)
{
    int sum = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (q.size())
    {
        auto [n, cur] = q.front();
        q.pop();
        cur = cur * 10 + n->val;
        if (n->left)
            q.push({n->left, cur});
        if (n->right)
            q.push({n->right, cur});
        if (!n->left && !n->right)
            sum += cur; // add to total sum if we are at leaf node
    }
    return sum;
}

/* Morris Traversal */

int sumNumbers(TreeNode *root)
{
    int sum = 0;
    int total_sum = 0, depth = 0, curr_sum = 0;
    if (root == NULL)
        return 0;

    TreeNode *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            curr_sum = curr_sum * 10 + curr->val;
            if (curr->right == NULL)
                total_sum += curr_sum;
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;
            depth = 1;
            while (prev->right != NULL and prev->right != curr)
            {
                prev = prev->right;
                depth++;
            }
            if (prev->right == NULL)
            {
                curr_sum = curr_sum * 10 + curr->val;
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                if (prev->left == NULL)
                    total_sum += curr_sum;
                curr_sum /= pow(10, depth);
                curr = curr->right;
            }
        }
    }
    return total_sum;
}

int main()
{
    return 0;
}