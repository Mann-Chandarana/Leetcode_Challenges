/*-------- Medium --------*/

/*- Pseudo-Palindromic Paths in a Binary Tree -*/

//////// Question number 1457.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/********************** Using Simple Traversal :- Approach -1)  **********************/

int pseudoPalindromic(vector<int> &arr)
{
    int count_odd = 0;
    for (int i = 1; i < 10; i++)
    {
        if (arr[i] & 1)
            count_odd++;
    }
    return count_odd < 2;
}

int countPaths(TreeNode *root, vector<int> &arr)
{
    if (root == NULL)
        return 0;

    arr[root->val]++;
    if (root->left == NULL and root->right == NULL)
    {
        bool answer = false;
        if (pseudoPalindromic(arr))
            answer = true;

        arr[root->val]--;
        return answer;
    }

    ///// Traversing left side

    int count_left = countPaths(root->left, arr);
    
    ///// Traversing Right side

    int count_right = countPaths(root->right, arr);

    arr[root->val]--;

    return count_left + count_right;
}

int pseudoPalindromicPaths(TreeNode *root)
{
    vector<int> arr(10, 0);
    return countPaths(root, arr);
}

/********************** Using bit manipulation :- Approach -2)  **********************/

int pseudoPalindromic(int number)
{
    int total = __builtin_popcount(number);

    return total < 2;
}

int countPaths(TreeNode *root, int number)
{
    if (root == NULL)
        return 0;

    number ^= (1 << (root->val));

    if (root->left == NULL and root->right == NULL)
    {
        bool answer = false;
        if (pseudoPalindromic(number))
            answer = true;

        return answer;
    }

    ///// Traversing left side

    int count_left = countPaths(root->left, number);

    ///// Traversing right side

    int count_right = countPaths(root->right, number);


    return count_left + count_right;
}

int pseudoPalindromicPaths(TreeNode *root)
{
    int number = 0;
    return countPaths(root, number);
}


/********************** Using bit manipulation :- Approach -3)  **********************/

int countPaths(TreeNode *root, int number)
{
    if (root == NULL)
        return 0;

    number ^= (1 << (root->val));

    if (root->left == NULL and root->right == NULL)
    {
        bool answer = false;
        if (number & (number-1))
            answer = true;

        return answer;
    }

    ///// Traversing left side

    int count_left = countPaths(root->left, number);

    ///// Traversing right side

    int count_right = countPaths(root->right, number);


    return count_left + count_right;
}

int pseudoPalindromicPaths(TreeNode *root)
{
    int number = 0;
    return countPaths(root, number);
}

int main()
{
    return 0;
}