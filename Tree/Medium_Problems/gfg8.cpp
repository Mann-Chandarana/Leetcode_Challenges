/* Top view of the tree */

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> topView(Node *root)
{
    map<int, int> mp;

    queue<pair<int, Node *>> q;
    q.push({0, root});

    while (!q.empty())
    {
        pair<int, Node *> p = q.front();
        q.pop();

        int x = p.first;
        Node *temp = p.second;

        if (mp.find(x) == mp.end())
        {
            mp[x] = temp->data;
        }

        if (temp->left != NULL)
            q.push({x - 1, temp->left});

        if (temp->right != NULL)
            q.push({x + 1, temp->right});
    }

    vector<int> ans;
    for (auto element : mp)
    {
        ans.push_back(element.second);
    }
    return ans;
}

int main()
{
    return 0;
}