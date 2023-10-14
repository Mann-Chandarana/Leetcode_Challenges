/* https://lightoj.com/problem/digit-count */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// dp[currDigit][prevDigit]

int dp[12][12];

ll go(int n, vector<ll> &s, ll pos = 0, ll prev = 0)
{
    ll res = 0;
    if (dp[pos][prev] != -1)
        return dp[pos][prev];

    if (pos == n)
        return 1;

    for (ll j = 0; j < s.size(); j++)
    {
        if (prev == 0 or (abs(prev - s[j])) <= 2)
            res += go(n, s, pos + 1, s[j]);
    }
    return res = dp[pos][prev];
}

int main()
{
    ll t;
    cin >> t;

    for (ll i = 0; i <= t; i++)
    {
        ll m, n;
        cin >> m >> n;

        vector<ll> s(m);

        for (auto &i : s)
            cin >> i;

        memset(dp, -1, sizeof(dp));

        ll ans = go(n, s);

        cout << "Case " << i << ": " << ans << endl;
    }

    return 0;
}