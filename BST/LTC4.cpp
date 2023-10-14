/*** Geeks for Geeks :- Minimum element in BST ****/

#include <bits/stdc++.h>
using namespace std;

int minValue(Node *root)
{
    if(root==NULL)
      return -1;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int main()
{
    return 0;
}