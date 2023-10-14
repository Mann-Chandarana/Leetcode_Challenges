/*--------  Hard --------*/

/*- Number of Beautiful Integers in the Range -*/

//////// Question number 2827.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
Here we have to consider two cases in recursion call 
1) The number containing leading zero
2) The number does not containing leading zero
*/

int dp[2][12][12][12][20][2];
int countNums(int k, string &nums, int tight = 1, int i = 0, int odd = 0, int even = 0, int rem = 0, bool leading = true)
{
    if (i == nums.size())
        return (!leading && rem == 0 && odd == even);

    if (dp[tight][i][odd][even][rem][leading] != -1)
        return dp[tight][i][odd][even][rem][leading];

    int end = (tight ? nums[i] - '0' : 9);
    int ans = (leading ? countNums(k, nums, 0, i + 1, odd, even, rem, true) : 0);

    for (int dig = 0; dig <= end; dig++)
    {
        int newTight = tight && (dig == (nums[i] - '0'));
        int newOdd = odd + (dig % 2);
        int newEven = even + ((!leading || dig > 0) && dig % 2 == 0);

        if ((leading && dig != 0) || !leading)
            ans += countNums(k, nums, newTight, i + 1, newOdd, newEven, (rem * 10 + dig)%k, false);

        dp[tight][i][odd][even][rem][leading] = ans;
    }

    return dp[tight][i][odd][even][rem][leading];
}

int numberOfBeautifulIntegers(int low, int high, int k)
{
    string s_low = to_string(low);
    string s_high = to_string(high);

    memset(dp, -1, sizeof(dp));
    int max_count = countNums(k, s_high);

    memset(dp, -1, sizeof(dp));
    int min_count = countNums(k, s_low);

    return max_count - min_count;
}

int main()
{
    return 0;
}