/*-------- Medium -----------*/

/*- Construct Binary Tree from Inorder and Postorder Traversal  -*/

//////// Question number 106.

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

TreeNode *build(vector<int> &inorder, vector<int> &postorder, int &index, int n, unordered_map<int, int> &mp, int start, int end)
{
    if (index < 0 || start > end)
        return NULL;

    int element = postorder[index];
    index--;
    TreeNode *root = new TreeNode(element);
    int pos = find(inorder.begin(),inorder.end(),element)-inorder.begin();
    root->right = build(inorder, postorder, index, n, mp, pos + 1, end);
    root->left = build(inorder, postorder, index, n, mp, start, pos - 1);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = postorder.size();
    unordered_map<int, int> mp;
    find(inorder, n, mp);
    int index = n-1;
    return build(inorder, postorder, index, n, mp, 0, n - 1);
}

int main()
{

    return 0;
}