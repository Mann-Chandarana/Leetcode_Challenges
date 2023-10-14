/*--------Medium-----------*/

/*- Find the Smallest Divisor Given a Threshold -*/

//////// Question number 1283.

#include <bits/stdc++.h>
using namespace std;

bool func(vector<int> &nums, int K, long long m)
{
    long long sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i] / m + (nums[i] % m != 0);
    }
    if (sum <= K)
        return true;
    else
        return false;
}

int smallestDivisor(vector<int> &nums, int K)
{
    long long l = 1;
    long long h = *max_element(nums.begin(), nums.end());
    long long ans = 0;
    while (l <= h)
    {
        long long m = (l + h) / 2;
        if (func(nums, K, m))
        {
            ans = m;
            h = m - 1;
        }
        else
            l = m + 1;
    }
    return ans;
}

int main()
{
    return 0;
}