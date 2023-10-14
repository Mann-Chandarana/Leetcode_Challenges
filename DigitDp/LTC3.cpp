/*--------  Hard --------*/

/*- Count of Integers -*/

//////// Question number 2719.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int mod = 1e9 + 7;

int dp[24][2][401];

int solve(string &nums, int min_sum, int max_sum, int pos = 0, int tight = 1, int sum = 0)
{
    if (pos == nums.size())
    {
        if (sum >= min_sum and sum <= max_sum)
            return 1;
        else
            return 0;
    }

    if (dp[pos][tight][sum] != -1)
        return dp[pos][tight][sum];

    ll end = tight ? (nums[pos] - '0') : 9;

    ll ans = 0;
    for (ll i = 0; i <= end; i++)
        ans += (solve(nums, min_sum, max_sum, pos + 1, (tight && (i == nums[pos] - '0')), (sum + i))) % mod;

    return (dp[pos][tight][sum] = (ans % mod));
}

int count(string num1, string num2, int min_sum, int max_sum)
{
    memset(dp, -1, sizeof(dp));
    ll high = (solve(num2, min_sum, max_sum)) % mod;

    memset(dp, -1, sizeof(dp));
    ll low = (solve(num1, min_sum, max_sum)) % mod;

    ll result = (high - low);
    
    result += mod;
    result %= mod;

    ll atNum1 = 0;
    for (int i = 0; i < num1.size(); i++)
        atNum1 += (num1[i] - '0');

    return (result + ((atNum1 >= min_sum and atNum1 <= max_sum) ? 1 : 0)) % mod;
}

int main()
{
    cout << count("1", "5", 1, 5) << endl;
    return 0;
}