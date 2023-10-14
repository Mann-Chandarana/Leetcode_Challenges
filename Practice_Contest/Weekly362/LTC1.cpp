/* 2848. Points That Intersect With Cars */

#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define vi vector<int>

/* Short way */

int numberOfPoints(vector<vector<int>> &nums)
{
    int n = nums.size();

    sort(all(nums));

    int ans = 0, k = 0;

    for (auto &i : nums)
    {
        if (i[1] > k)
        {
            ans += (i[1] - max(i[0] - 1, k));
        }
        k = max(i[1], k);
    }
    return ans;
}

int main()
{
    return 0;
}