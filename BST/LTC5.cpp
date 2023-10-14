/* Geeks for Geeks :-  find the Ceil */

#include <bits/stdc++.h>
using namespace std;

/*** Using Iteraiton ***/

int findCeil(Node *root, int input)
{
    int res = -1;
    while (root)
    {
        if (input == root->data)
        {
            res = input;
            break;
        }
        if (root->data < input)
        {
            root = root->right;
        }
        else
        {
            res = root->data;
            root = root->left;
        }
    }
    return res;
}

/*** Using Recursion ***/

Node *search(Node *root, int input, int &successor)
{
    if (root == NULL)
        return NULL;

    if (root->data == input)
        return root;

    else if (input > root->data)
        return search(root->right, input, successor);

    else
    {
        successor = root->data;
        return search(root->left, input, successor);
    }
}

int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;

    int ans = INT_MAX;
    root = search(root, input, ans);
    if (root != NULL)
        return input;

    else
    {
        if (ans != INT_MAX)
            return ans;
        return -1;
    }
}

int main()
{
    return 0;
}