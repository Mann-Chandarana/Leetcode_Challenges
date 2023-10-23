/*--------  Hard --------*/

/*- Constrained Subsequence Sum -*/

//////// Question number 1425.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

typedef pair<int, int> pi;

/********* Optimised Approach *********/

int constrainedSubsetSum(vector<int> &nums, int k)
{
    int n = nums.size();

    vector<int> dp(n);

    for (int i = 0; i < n; i++)
        dp[i] = nums[i];

    int result = dp[0];
    priority_queue<pi> pq;

    int maxR = dp[0];

    pq.push({dp[0], 0});

    for (int i = 1; i < n; i++)
    {
        while (!pq.empty() and i - pq.top().second > k)
            pq.pop();

        dp[i] = max(dp[i], pq.top().first + nums[i]);
        pq.push({dp[i], i});
        maxR = max(maxR, dp[i]);
    }
    return maxR;
}

/********* Recursion + Memorization *********/

int solve(int index, int prev, int &k, int &n, vector<int> &nums, vector<vector<int>> &dp)
{
    if (index >= n)
        return 0;

    if (dp[index][prev + 1] != -1)
        return dp[index][prev + 1];

    int take = INT_MIN, not_take = INT_MIN;

    if (prev == -1 || index - prev <= k)
    {
        take = nums[index] + solve(index + 1, index, k, n, nums, dp);
    }
    not_take = 0 + solve(index + 1, prev, k, n, nums, dp);

    return dp[index][prev + 1] = max(take, not_take);
}

int constrainedSubsetSum(vector<int> &nums, int k)
{
    int n = nums.size();

    /* Handling the all the negative elements case */
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= 0)
            pos++;
    }
    if (pos == 0)
        return *max_element(nums.begin(), nums.end());

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(0, -1, k, n, nums, dp);
}

/********* Tabulation *********/

int constrainedSubsetSum(vector<int> &nums, int k)
{
    int n = nums.size();

    /* Handling the all the negative elements case */

    //////// Case - 1)

    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= 0)
            pos++;
    }
    if (pos == 0)
        return *max_element(nums.begin(), nums.end());

    /////// Case - 2)

    vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int prev = n; prev >= 0; prev--)
        {
            int take = INT_MIN, not_take = INT_MIN;

            if (index - prev <= k)
                take = nums[index] + dp[index + 1][index];

            not_take = 0 + dp[index + 1][prev];

            dp[index][prev] = max(take, not_take);
        }
    }

    for (int i = 0; i <= n; i++)
        dp[0][0] = max(dp[0][0], dp[0][i]);

    return dp[0][0];
}

/********* Tabulation - 2) *********/

int constrainedSubsetSum(vector<int> &nums, int k)
{
    int n = nums.size();

    /* Handling the all the negative elements case */

    //////// Case - 1)

    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= 0)
            pos++;
    }
    if (pos == 0)
        return *max_element(nums.begin(), nums.end());

    /////// Case - 2)

    vector<int> dp(n);

    for (int i = 0; i < n; i++)
        dp[i] = nums[i];

    int result = dp[0];

    for (int index = 1; index < n; index++)
    {
        for (int prev = index - 1; index - prev <= k and prev >= 0; prev--)
        {
            if (dp[prev] + nums[index] > dp[index])
                dp[index] = dp[prev] + nums[index];
        }
        result = max(result, dp[index]);
    }
    return result;
}

int main()
{
    return 0;
}