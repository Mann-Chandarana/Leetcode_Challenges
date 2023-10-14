// geeks for geeks :- Children Sum Parent

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

/*** Using Recurison ***/

int isSumProperty(Node *root)
{
    if (root == NULL || (root->left == NULL and root->right == NULL))
        return 1;

    int sum = 0;

    if (root->left)
        sum += root->left->data;

    if (root->right)
        sum += root->right->data;

    return (sum == root->data && isSumProperty(root->left) && isSumProperty(root->right));
}

/*** Using Iteration or breadth first search ***/

int isSumProperty(Node *root)
{
    if (root == NULL)
        return 1;

    queue<Node *> q;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int sum = 0;
        if (temp->left)
        {
            sum += temp->left->data;
            q.push(temp->left);
        }

        if (temp->right)
        {
            sum += temp->right->data;
            q.push(temp->right);
        }
        if (temp->left == NULL and temp->right == NULL)
            continue;
        else if (temp->data != sum)
            return 0;
    }

    return 1;
}

int main()
{
    return 0;
}