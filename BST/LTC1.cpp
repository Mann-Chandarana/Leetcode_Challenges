/*- Range sum of BST -*/

//////// Question number 938.

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

void find(TreeNode *root, int low, int high, int &answer)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->val >= low and root->val <= high)
    {
        answer += (root->val);
    }

    find(root->left, low, high, answer);
    find(root->right, low, high, answer);
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    int answer = 0;
    find(root, low, high, answer);
    return answer;
}

int main()
{

    return 0;
}