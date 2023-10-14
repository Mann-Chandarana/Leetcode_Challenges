/*-------- Medium -----------*/

/*- Binary Search Tree Iterator -*/

//////// Question number 173.

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

class BSTIterator
{
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        pushAllLeft(root);
    }

    int next()
    {
        int val = st.top()->val;
        TreeNode *temp = st.top();
        st.pop();
        if (temp->right)
        {
            pushAllLeft(temp->right);
        }
    }

    bool hasNext()
    {
        return !st.empty();
    }

    void pushAllLeft(TreeNode *root)
    {
        TreeNode *temp = root;
        while (temp)
        {
            st.push(temp);
            temp = temp->left;
        }
    }
};

int main()
{
    return 0;
}