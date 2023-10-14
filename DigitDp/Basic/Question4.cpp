/* SPOJ Problem :- LUCIFER - LUCIFER Number */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

ll prime[17] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
ll dp[12][2][60][60];

ll is_prime(ll odd_sum, ll even_sum, ll len)
{
    ll diff;
    if (len % 2 == 0)
        diff = even_sum - odd_sum;
    else
        diff = odd_sum - even_sum;
    if (diff < 0)
        return 0;
    else
    {
        for (ll i = 0; i < 17; i++)
            if (prime[i] == diff)
                return 1;
        return 0;
    }
}

ll go(string &str, ll idx = 0, ll tight = 1, ll odd_sum = 0, ll even_sum = 0)
{
    if (idx >= str.length())
        return is_prime(odd_sum, even_sum, str.length());
    else if (dp[idx][tight][odd_sum][even_sum] != -1)
        return dp[idx][tight][odd_sum][even_sum];
    else if (tight == 1)
    {
        ll cnt = 0;
        for (ll i = 0; i <= str[idx] - '0'; i++)
        {
            ll od = odd_sum, ev = even_sum;
            if (idx & 1)
                od += i;

            else
                ev += i;

            if (i == str[idx] - '0')
                cnt += go(str, idx + 1, 1, od, ev);
            else
                cnt += go(str, idx + 1, 0, od, ev);
        }
        return dp[idx][tight][odd_sum][even_sum] = cnt;
    }
    else
    {
        ll cnt = 0;
        for (ll i = 0; i <= 9; i++)
        {
            ll od = odd_sum, ev = even_sum;
            if (idx & 1)
                od += i;

            else
                ev += i;
            cnt += go(str, idx + 1, 0, od, ev);
        }
        return dp[idx][tight][odd_sum][even_sum] = cnt;
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        ll temp = stoll(a) - 1;
        a = to_string(temp);
        memset(dp, -1, sizeof(dp));
        ll ans1 = go(b);
        memset(dp, -1, sizeof(dp));
        ll ans2 = go(a);
        cout << ans1 - ans2 << endl;
    }
}