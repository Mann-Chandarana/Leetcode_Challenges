/*-------- Hard --------*/

/*- Count the Number of Good Partitions -*/

//////// Question number 2963.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int mod = 1e9 + 7;

int numberOfGoodPartitions(vector<int> &nums)
{
    int n = nums.size();

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[nums[i]] = i;

    int i = 0, j = 0, result = 1;
    j = max(j, mp[nums[0]]);

    while (i < n)
    {
        if (i > j)
            result = (result * 2) % mod;

        j = max(j, mp[nums[i]]);
        i++;
    }
    return result;
}

int main()
{
    return 0;
}