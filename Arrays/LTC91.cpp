/* 1732. Find the Highest Altitude */

#include <bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int> &gain)
{
    int ans = INT_MIN;
    int preSum = 0;

    for (int i = 0; i < gain.size(); i++)
    {

        ans = max(preSum, ans);
        preSum += gain[i];
    }

    if (preSum > ans)
        ans = preSum;

    return ans;
}

int main()
{
    return 0;
}