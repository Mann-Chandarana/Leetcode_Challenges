/*--------  Medium --------*/

/*- Happy Students -*/

//////// Question number 2860.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int countWays(vector<int> &nums)
{
    int n = nums.size();
    sort(all(nums));
    int ans = 0;

    if (nums[0] != 0)
        ans++;

    int selected = 0;
    for (int i = 0; i < n; i++)
    {
        selected++;
        if (selected > nums[i])
        {
            if (i + 1 < n and selected + 1 <= nums[i + 1])
                ans++;
        }
        if (i == n - 1)
        {
            if (selected > nums[i])
                ans++;
        }
    }
    return ans;
}

int main()
{
    return 0;
}