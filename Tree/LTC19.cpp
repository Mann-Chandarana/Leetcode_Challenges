/*-------- Medium -----------*/

/*- Count Nodes Equal to Average of Subtree -*/

//////// Question number 2265.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int answer = 0;

pair<int, int> f(TreeNode *root)
{
    if (root == NULL)
        return {0, 0};

    pair<int, int> left = f(root->left);   // {sum,numberOfNodes}
    pair<int, int> right = f(root->right); // {sum,numberOfNodes}

    int sum = (root->val + left.first + right.first) / (left.second + right.second + 1);

    if (sum == root->val)
        answer++;

    return {(root->val + left.first + right.first), (left.second + right.second + 1)};
}

int averageOfSubtree(TreeNode *root)
{
    f(root);

    return answer;
}

int main()
{
    return 0;
}