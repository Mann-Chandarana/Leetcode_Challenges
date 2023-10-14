/* Geeks for Geeks :-  find the Floor */

#include <bits/stdc++.h>
using namespace std;

int floor(Node *root, int x)
{
    int res = -1;

    while (root)
    {
        if (root->data == x)
            return root->data;

        else if (x < root->data)
            root = root->left;

        else
        {
            res = root->data;
            root = root->left;
        }
    }
    return res;
}

int main()
{
    return 0;
}