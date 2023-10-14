/*- Leaf-Similar Trees  -*/

//////// Question number 872.

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

void leaf(TreeNode *root, vector<int> &leafNodes)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL and root->right==NULL)
    {
        leafNodes.push_back(root->val);
        return;
    }

    leaf(root->left, leafNodes);
    leaf(root->right, leafNodes);
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<int> val1, val2;
    leaf(root1, val1);
    leaf(root2, val2);

    if (val1.size() != val2.size())
    {
        return false;
    }

    for (int i = 0; i < val1.size(); i++)
    {
        if (val1[i] != val2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    return 0;
}