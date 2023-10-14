// 94. Binary Tree Inorder Traversal

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

/*** Recursive solution ***/

void solve(TreeNode *root, vector<int> &answer)
{
    if (root == NULL)
    {
        return;
    }

    solve(root->left, answer);
    answer.push_back(root->val);
    solve(root->right, answer);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> answer;
    solve(root, answer);

    return answer;
}

/*** Iterative solution ***/

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> answer;

    stack<TreeNode *> st;

    while (root || !st.empty())
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();

        answer.push_back(root->val);

        root = root->right;
    }

    return answer;
}

int main()
{
    return 0;
}