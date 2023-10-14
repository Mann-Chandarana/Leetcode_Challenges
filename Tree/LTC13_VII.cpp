/*-------- Hard -----------*/

/*- Find Duplicate Subtrees  -*/

//////// Question number 652.

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

string encode(TreeNode *root, unordered_map<string, int> &count,
              vector<TreeNode *> &ans)
{
    if (root == NULL)
        return "";

    string encoded = to_string(root->val) + "#" + encode(root->left, count, ans) + "#" + encode(root->right, count, ans);

    if (++count[encoded] == 2)
        ans.push_back(root);

    return encoded;
}

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    vector<TreeNode *> ans;
    unordered_map<string, int> count;
    encode(root, count, ans);
    return ans;
}

int main()
{
    return 0;
}