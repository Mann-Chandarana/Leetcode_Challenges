/* Geeks for Geeks :- Binary Search Trees */

/*
In Binary search tree , inorder traversal is always sorted
*/

#include <bits/stdc++.h>
using namespace std;

bool isBSTTraversal(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i + 1] <= nums[i])
            return false;
    }
    return true;
}

int main()
{
    return 0;
}