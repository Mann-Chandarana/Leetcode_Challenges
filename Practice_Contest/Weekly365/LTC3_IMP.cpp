/*-------- Medium -----------*/

/*- Minimum Size Subarray in Infinite Array -*/

//////// Question number 2875.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int minSizeSubarray(vector<int> &nums, int target)
{
    ll n = nums.size();
    ll sum = accumulate(all(nums), 0LL);

    ll num = target / sum;
    ll rem = target % sum;

    if (rem == 0)
        return num * n;

    unordered_map<ll, int> mp;

    ll temp = 0;
    int ans = INT_MAX;

    for (int i = 0; i < 2 * n; i++)
    {
        temp += nums[i % n];
        if (mp.find(temp - rem) != mp.end())
            ans = min(ans, i - mp[temp - rem]);

        mp[temp] = i;
    }
    return ans == INT_MAX ? -1 : ans + num * n;
}

int main()
{
    return 0;
}