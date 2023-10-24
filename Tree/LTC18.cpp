/*-------- Medium -----------*/

/*- Find Largest Value in Each Tree Row  -*/

//////// Question number 515.

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

vector<int> largestValues(TreeNode *root)
{
    vector<int> answer;
    if (root == NULL)
        return answer;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            maxi = max(maxi, node->val);

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
        answer.push_back(maxi);
    }
    return answer;
}

int main()
{
    return 0;
}