/*--------  Medium --------*/

/*- Largest Element in an Array after Merge Operations -*/

//////// Question number 2789.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpii vector<pair<int, int>>
#define vppi vector<pair<pair<int, int>, int>>

long long maxArrayValue(vector<int> &nums)
{
    int n = nums.size();
    ll maxi = LONG_MIN;
    ll sum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] > sum)
            sum = 0;

        sum += nums[i];
        maxi = max(maxi, sum);
    }
    return maxi;
}

int main()
{
    return 0;
}