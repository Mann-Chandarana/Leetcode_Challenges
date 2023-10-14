/*-------- Medium -----------*/

/*- Serialize and Deserialize Binary Tree  -*/

//////// Question number 297.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    string serialize(TreeNode *root)
    {
        string ans = "";
        if (root == NULL)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            if (curr == NULL)
            {
                ans.append("#,");
            }
            else
            {
                ans += to_string(curr->val) + ',';
                if (curr->left)
                {
                    q.push(curr->left);
                }
                else
                {
                    q.push(NULL);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
                else
                {
                    q.push(NULL);
                }
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
        {
            return NULL;
        }
        stringstream ss(data);
        string str;
        getline(ss, str, ',');

        TreeNode *ans;
        queue<TreeNode *> q;

        // Making the first character as the root of the tree.
        ans = new TreeNode(stoi(str));
        q.push(ans);

        // Recreating the tree from the serialize string.
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            getline(ss, str, ','); // helps us to fetch a character before ','
            if (str == "#")
            {
                curr->left = NULL;
            }
            else
            {
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }

            getline(ss, str, ',');
            if (str == "#")
            {
                curr->right = NULL;
            }
            else
            {
                curr->right = new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}