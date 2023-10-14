/*** Geeks for geeks :- Largest BST ***/ 

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

int ans = 0;

vector<int> findBst(Node *root,int &ans)
{
    if (root == NULL)
    {
        // min     max
        return {INT_MAX, INT_MIN, 1, 0};
    }

    vector<int> left = findBst(root->left,ans);
    vector<int> right = findBst(root->right,ans);

    vector<int> curr(4);
    curr[0] = min(root->data, left[0]);
    curr[1] = max(root->data, right[1]);

    if (left[2] == 1 and right[2] == 1 and root->data > left[1] and root->data < right[0])
        curr[2] = 1;
    else
        curr[2] = 0;

    curr[3] = left[3] + right[3] + 1;
    if (curr[2])
        ans = max(ans, curr[3]);
    return curr;
}

int largestBst(Node *root)
{
    int ans = 0;
    findBst(root,ans);
    return ans;
}

int main()
{
    return 0;
}