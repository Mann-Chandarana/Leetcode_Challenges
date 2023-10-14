/*-------- Medium -----------*/

/*- Largest Divisible Subset -*/

//////// Question number 368.

#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1), hash(n, 1);
    int maxi = INT_MIN;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev <= i - 1; prev++)
        {
            if (arr[i] % arr[prev] == 0 and 1 + dp[prev] > dp[i])
            {
                dp[i] = dp[prev] + 1;
                hash[i] = prev;
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int ans = -1, last_index = -1;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
            last_index = i;
        }
    }

    vector<int> answer;
    answer.push_back(arr[last_index]);
    while (hash[last_index] != last_index)
    {
        last_index = hash[last_index];
        answer.push_back(arr[last_index]);
    }

    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    return 0;
}