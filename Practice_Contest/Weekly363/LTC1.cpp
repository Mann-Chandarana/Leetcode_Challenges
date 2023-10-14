/* 2859. Sum of Values at Indices With K Set Bits */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/**** Approach -1) *****/

int no_of_setBit(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n & (-n))
            count++, n = (n & (n - 1));
    }
    return count;
}

int sumIndicesWithKSetBits(vector<int> &nums, int k)
{
    int n = nums.size();
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (no_of_setBit(nums[i]) == k)
            sum += nums[i];
    }
    return sum;
}

/**** Approach -2) Using Dynamic programming *******/

int sumIndicesWithKSetBits(vector<int> &nums, int k)
{
    int n = nums.size();
    ll sum = k == 0 ? nums[0] : 0, n = nums.size();

    vector<int> counts(1);
    for (int i = 1; i < n; i++)
    {
        counts.push_back(counts[i & (i - 1)] + 1);

        if (counts.back() == k)
            sum += nums[i];
    }
    return sum;
}

int main()
{
    return 0;
}