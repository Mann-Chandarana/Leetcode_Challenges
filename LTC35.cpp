/*-------- Medium --------*/

/*- Even Odd Tree -*/

//////// Question number 1609.

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

bool isEvenOddTree(TreeNode *root)
{
    int check = false;

    queue<TreeNode *> q;
    q.push(root);
    bool order = 0; // 0 is odd , 1 is even

    while (!q.empty())
    {
        int n = q.size();
        int prev = -1;

        cout << order << endl;

        while (n--)
        {
            TreeNode *node = q.front();
            q.pop();

            if ((prev != -1) and ((order and prev <= node->val) || (!order and prev >= node->val)))
                return false;

            if ((!order and !(node->val & 1)) || (order and (node->val & 1)))
                return false;

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);

            prev = node->val;
        }
        order = !order;
    }
    return true;
}

int main()
{
    return 0;
}