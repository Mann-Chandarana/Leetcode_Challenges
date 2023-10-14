/*-------- Medium -----------*/

/*- Construct Binary Tree from Preorder and Inorder Traversal  -*/

//////// Question number 105.

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

void find(vector<int> &inorder, int n, unordered_map<int, int> &mp)
{
    for (int i = 0; i < n; i++)
    {
        mp[inorder[i]] = i;
    }
}

TreeNode *build(vector<int> &preorder, vector<int> &inorder, int start, int end, int &index, int n, unordered_map<int, int> &mp)
{
    if (index >= n or start > end)
        return NULL;

    int element = preorder[index];
    index++;
    TreeNode *root = new TreeNode(element);

    int pos = mp[element];

    root->left = build(preorder, inorder, start, pos - 1, index, n, mp);
    root->right = build(preorder, inorder, pos + 1, end, index, n, mp);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = preorder.size();
    int index = 0;
    unordered_map<int, int> mp;
    find(inorder, n, mp);
    return build(preorder, inorder, 0, n - 1, index, n,mp);
}

int main()
{
    return 0;
}