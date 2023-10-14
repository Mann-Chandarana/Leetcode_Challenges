/*--------  Medium --------*/

/*- Minimum Absolute Difference Between Elements With Constraint -*/

//////// Question number 2817.

#include <bits/stdc++.h>
using namespace std;

int minAbsoluteDifference(vector<int> &nums, int x)
{
    set<int> s;
    int n = nums.size();
    int ans = INT_MAX;

    for (int i = x; i < n; i++)
    {
        s.insert(nums[i - x]);
        auto ind = s.lower_bound(nums[i]);

        if (ind != s.end())
            ans = min(ans, abs(*ind - nums[i]));

        if (ind != s.begin())
        {
            ind--;
            ans = min(ans, abs(*ind - nums[i]));
        }
    }

    return ans;
}

int main()
{
    return 0;
}