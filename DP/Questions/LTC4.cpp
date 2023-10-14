/*--------  Medium --------*/

/*- Maximum Length of Pair Chain -*/

//////// Question number 646.

#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

/* 1) Greedy solution */

int findLongestChain(vector<vector<int>> &pairs)
{
    int n = pairs.size();
    sort(all(pairs), [](const vector<int> &a, const vector<int> &b)
         { return a[1] < b[1]; });

    int curr = INT_MIN, ans = 0;

    for (auto &pair : pairs)
    {
        if (curr < pair[0])
        {
            curr = pair[1];
            ans++;
        }
    }
    return ans;
}

/* 2) Dynamic programming */

int findLongestChain(vector<vector<int>> &pairs)
{
    int n = pairs.size();
    sort(all(pairs));
    vector<int> dp(n, 1);

    int maxi = 1;

    for (int i = 1; i < pairs.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (pairs[j][1] < pairs[i][0] and dp[i] < 1 + dp[j])
                dp[i] = 1 + dp[j];
        }
        maxi = max(maxi, dp[i]);
    }

    return maxi;
}

int main()
{
    return 0;
}