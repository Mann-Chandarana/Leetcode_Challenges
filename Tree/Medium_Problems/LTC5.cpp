/* Easy :- 100. Same Tree */

#include <bits/stdc++.h>
using namespace std;

/**** Using  Recursion ****/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSame(TreeNode *p, TreeNode *q)
{
    if (p == NULL and q == NULL)
        return true;

    if ((p == NULL and q != NULL) or (p != NULL and q == NULL) || p->val != q->val)
        return false;

    return (isSame(p->left, q->left) and isSame(p->right, q->right));
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    return isSame(p, q);
}

/**** Using iterative ****/

bool isSameTree(TreeNode *p, TreeNode *q)
{
    stack<pair<TreeNode *, TreeNode *>> st;

    st.push({p, q});

    while (!st.empty())
    {
        pair<TreeNode *, TreeNode *> p = st.top();
        st.pop();

        if (!p.first and !p.second)
            continue;

        if ((p.first != NULL and p.second == NULL) or (p.first == NULL and p.second != NULL) or (p.first->val != p.second->val))
            return false;

        st.push({p.first->left, p.second->left});
        st.push({p.first->right, p.second->right});
    }

    return true;
}

int main()
{
    return 0;
}