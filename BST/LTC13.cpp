/*** Geeks for Geeks :- Predecessor and Successor ***/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

Node *returnRight(Node *root)
{
    if (!root->right)
        return root;

    return returnRight(root->right);
}

Node *returnLeft(Node *root)
{
    if (!root->left)
        return root;

    return returnLeft(root->left);
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (root == NULL)
        return;

    if (root->key == key)
    {
        if (root->right)
            suc = returnLeft(root->right);

        if (root->left)
            pre = returnRight(root->left);

        return;
    }

    if (root->key > key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

int main()
{
    return 0;
}