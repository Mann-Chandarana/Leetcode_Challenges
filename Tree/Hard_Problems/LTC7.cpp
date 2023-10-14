// Geeks for geeks :- Unique Binary Tree Requirements

/* Unique binary tree requires exactly one inorder traversal */

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a, int b)
{
    if ((a == 2 || b == 2) && (a != b))
        return true;
    else
        return false;
}

int main()
{
    return 0;
}