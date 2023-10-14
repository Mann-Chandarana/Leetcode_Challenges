/* Void Create tree s*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return (node);
}

void create_tree(node *root0, vector<int> &vec)
{
    queue<node *> q;
    q.push(root0);
    int i = 1, n = vec.size();
    while (i < n)
    {
        node *root = q.front();
        q.pop();
        node *left = newNode(vec[i++]);
        root->left = left;
        q.push(left);
        if (i >= n)
            break;
        node *right = newNode(vec[i++]);
        root->right = right;
        q.push(right);
    }
}

int main()
{

    return 0;
}