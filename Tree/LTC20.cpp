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

/***
 Time Complexity :- O(N)
 Space Complexity :- O(N)
***/

unordered_map<int, int> mp;

void dfs(TreeNode *root)
{
    if (root == NULL)
        return;

    dfs(root->left);
    mp[root->val]++;
    dfs(root->right);
}

vector<int> findMode(TreeNode *root)
{
    dfs(root);
    vector<int> vec;

    int maxi = INT_MIN;

    for (auto element : mp)
    {
        if (element.second > maxi)
        {
            maxi = element.second;
            vec = {};
            vec.push_back(element.first);
        }
        else if (element.second == maxi)
            vec.push_back(element.first);
    }
    return vec;
}

/***
 Time Complexity :- O(N)
 Space Complexity :- O(1)
***/

int curNum = 0, maxStreak = 0, currStreak = 0;
vector<int> result;

void dfs(TreeNode *root)
{
    if (!root)
        return;

    dfs(root->left);

    if (root->val == curNum)
        currStreak++;
    else
    {
        curNum = root->val;
        currStreak = 1;
    }
    if (currStreak > maxStreak)
        result = {}, maxStreak = currStreak;

    if (currStreak == maxStreak)
        result.push_back(root->val);

    dfs(root->right);
}

vector<int> findMode(TreeNode *root)
{
    dfs(root);
    return result;
}

int main()
{
    return 0;
}