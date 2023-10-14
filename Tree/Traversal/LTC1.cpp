// 144. Binary Tree Preorder Traversal

#include <bits/stdc++.h>
using namespace std;

/* Preorder Traversal using recursion */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void solve(TreeNode *root, vector<int> answer)
{
    if (root == NULL)
        return;

    answer.push_back(root->val);
    solve(root->left, answer);
    solve(root->right, answer);
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> answer;

    solve(root, answer);

    return answer;
}
/* Preorder Traversal using iteration */

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> answer;

    if (root == NULL)
    {
        return;
    }

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *temp = st.top();
        st.pop();

        answer.push_back(temp->val);

        if (temp->right != NULL)
            st.push(temp->right);

        if (temp->left != NULL)
            st.push(temp->left);
    }

    return answer;
}

int main()
{
    return 0;
}