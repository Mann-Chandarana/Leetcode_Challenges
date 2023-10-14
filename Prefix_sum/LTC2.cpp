/*-------- Medium -----------*/

/*- Product of Array Except Self -*/

//////// Question number 238.

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity - O(n)
Space complexity -O(n)
*/

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();

    vector<int> prefix(n), postfix(n);

    prefix[0] = nums[0];
    postfix[n - 1] = nums[n - 1];

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] * nums[i];

    for (int i = n - 2; i >= 0; i--)
        postfix[i] = postfix[i + 1] * nums[i];

    vector<int> res(n);

    res[0] = postfix[1];
    res[n - 1] = prefix[n - 2];

    for (int i = 1; i < n - 1; i++)
    {
        res[i] = prefix[i - 1] * postfix[i + 1];
    }

    return res;
}

/*
Time complexity - O(n)
Space complexity -O(1)
*/

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();

    vector<int> res(n, 1);
    res[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        res[i] = res[i - 1] * nums[i];
    }

    int fromEnd = 1;

    for (int i = n - 1; i > 0; i--)
    {
        res[i] = res[i - 1] * fromEnd;
        fromEnd *= nums[i];
    }

    res[0] = fromEnd;

    return res;
}

int main()
{
    vector<int> ar = {1, 2, 3, 4};
    ar = productExceptSelf(ar);

    for (auto element : ar)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}