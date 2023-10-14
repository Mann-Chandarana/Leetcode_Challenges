/*-------- Hard -----------*/

/*- Power of Heroes -*/

//////// Question number 2681.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int sumOfPower(vector<int> &nums)
{
    int n = nums.size();
    ll last2 = 0;
    ll last = 0;
    ll output = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        ll val = nums[i];
        ll v1 = (val * val) % mod;
        ll v2 = (last + last2 + val) % mod;
        output = (output + ((v1 * v2) % mod)) % mod;

        last2 = (((last2 + last) % mod) * 2) % mod;
        last = nums[i];
    }
    return output;
}

int main()
{
    vector<int> nums = {2, 1, 4};
    cout << sumOfPower(nums);
    return 0;
}