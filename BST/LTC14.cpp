/*** Geeks for geeks :- Merge two BST ***/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<int> merge(Node *root1, Node *root2)
{
    vector<int> vec;
    queue<Node *> q;
    q.push(root1);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        vec.push_back(temp->data);
        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    q.push(root2);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        vec.push_back(temp->data);
        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    sort(vec.begin(), vec.end());

    return vec;
}

int main()
{
    return 0;
}