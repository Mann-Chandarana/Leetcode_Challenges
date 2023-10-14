/* Easy :- 110. Balanced Binary Tree */

#include <bits/stdc++.h>
using namespace std;

/***** Using pair appraoch  *****/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

pair<int, bool> solve(TreeNode *root)
{
    if (root == NULL)
    {
        pair<int, int> p = {0, 1};
        return p;
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> answer;
    answer.first = 1 + max(left.first, right.first);

    if (left.second and right.second and (abs(left.first - right.first) <= 1))
        answer.second = true;

    else
        answer.second = false;

    return answer;
}

bool isBalanced(TreeNode *root)
{
    pair<int, int> answer = solve(root);

    return answer.second;
}

/***** Optimised space approach *****/

bool ans;
int checkBalance(TreeNode *root)
{
    if (!root || !ans)
        return 0;

    int left = checkBalance(root->left);
    int right = checkBalance(root->right);

    if (abs(left - right) > 1)
    {
        ans = false;
    }

    return 1 + max(left, right);
}

bool isBalanced(TreeNode *root)
{
    ans = true;
    int temp = checkBalance(root);
    return ans;
}

int main()
{
    return 0;
}