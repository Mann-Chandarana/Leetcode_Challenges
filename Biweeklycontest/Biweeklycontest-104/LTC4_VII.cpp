/*-------- Medium -----------*/

/*- Maximum OR -*/

//////// Question number 2680.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*************** Recursion **************/

long long solve(vector<int> &nums, int k, int index)
{
    if (index >= nums.size())
        return 0;

    ll taken = LONG_MIN, answer = -1;

    for (int i = 0; i <= k; i++)
    {
        taken = ((ll)nums[index] << i) | solve(nums, k - i, index + 1);
        answer = max(taken, answer);
    }

    return answer;
}

/*************** Memorization **************/

long long solve(vector<int> &nums, int k, int index, vector<vector<ll>> &dp)
{
    cout << "Hello" << endl;
    if (index >= nums.size())
        return 0;

    if (dp[index][k] != -1)
        return dp[index][k];

    ll taken = LONG_MIN, answer = -1;

    for (int i = 0; i <= k; i++)
    {
        taken = ((ll)nums[index] << i) | solve(nums, k - i, index + 1, dp);
        answer = max(taken, answer);
    }

    return dp[index][k] = answer;
}

long long maximumOr(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<vector<ll>> dp(n, vector<ll>(k + 1, -1));
    return solve(nums, k, 0, dp);
}

/*************** Tabulation **************/

long long maximumOr(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        ll taken = LONG_MIN, answer = -1;

        for (int i = 0; i <= k; i++)
        {
            taken = ((ll)nums[index] << i) | dp[index + 1][k - i];
            answer = max(taken, answer);
            dp[index][i] = answer;
        }
    }
    return dp[0][k];
}

/* Prefix and Suffix or */

long long maximumOr(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<ll> prefix(n, 0);
    vector<ll> suffix(n, 0);

    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] | nums[i - 1];

    for (int i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] | nums[i + 1];

    ll res = LONG_LONG_MIN;

    for (int i = 0; i < n; i++)
    {
        res = max(res, prefix[i] | ((1ll << k) * nums[i]) | suffix[i]);
    }
    return res;
}

int main()
{
    vector<int> nums = {12, 9};
    cout << maximumOr(nums, 1) << endl;
    return 0;
}