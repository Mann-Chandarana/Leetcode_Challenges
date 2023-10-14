// Geeks for geeks :- Burning Tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

Node *findParent(unordered_map<Node *, Node *> &mp, Node *root, int target)
{
    Node *ans = NULL;
    queue<Node *> q;
    mp[root] = NULL;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->data == target)
            ans = temp;

        if (temp->left)
        {
            mp[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            mp[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return ans;
}

int minTime(Node *root, int target)
{
    unordered_map<Node *, Node *> node_to_parent;
    unordered_map<Node *, int> visited;
    Node *tar = findParent(node_to_parent, root, target);

    int time = 0;

    queue<Node *> q;
    q.push(tar);
    visited[tar] = 1;

    while (!q.empty())
    {
        int size = q.size();
        bool isEntered = false;
        while (size--)
        {

            Node *temp = q.front();
            q.pop();

            if (temp->left != NULL and !visited[temp->left])
            {
                // cout<<temp->left->data<<" ";
                isEntered = true;
                visited[temp->left] = 1;
                q.push(temp->left);
            }
            if (temp->right != NULL and !visited[temp->right])
            {
                // cout<<temp->right->data<<" ";
                isEntered = true;
                visited[temp->right] = 1;
                q.push(temp->right);
            }
            if (node_to_parent[temp] != NULL and !visited[node_to_parent[temp]])
            {
                // cout<<node_to_parent[temp]->data<<" ";
                isEntered = true;
                visited[node_to_parent[temp]] = 1;
                q.push(node_to_parent[temp]);
            }
        }
        if (isEntered)
            time++;
    }

    return time;
}

int main()
{
    return 0;
}