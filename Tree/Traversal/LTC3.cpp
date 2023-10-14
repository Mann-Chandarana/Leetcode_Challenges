// 145. Binary Tree Postorder Traversal

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

/*** Using recursion ***/

void solve(TreeNode *root, vector<int> &answer)
{
    if (root == NULL)
    {
        return;
    }

    solve(root->left, answer);
    solve(root->right, answer);
    answer.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> answer;
    solve(root, answer);

    return answer;
}

/*** Using Iteration  ***/

// 1) Using two stacks

vector<int> postorderTraversal(TreeNode *curr)
{
    vector<int> postorder;

    stack<TreeNode *> st1, st2;
    st1.push(curr);
    while (!st1.empty())
    {
        curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left != NULL)
        {
            st1.push(curr->left);
        }
        if (curr->right != NULL)
        {
            st1.push(curr->right);
        }
    }

    while (!st2.empty())
    {
        postorder.push_back(st2.top()->val);
        st2.pop();
    }
    return postorder;
}

// 2) Using 1 Stack

vector<int> postOrderTrav(TreeNode *cur)
{
    vector<int> postOrder;
    if (cur == NULL)
        return postOrder;

    stack<TreeNode *> st;
    while (cur != NULL || !st.empty())
    {
        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->val);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->val);
                }
            }
            else
                cur = temp;
        }
    }
    return postOrder;
}

int main()
{
    return 0;
}