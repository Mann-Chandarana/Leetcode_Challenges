/* 1913. Maximum Product Difference Between Two Pairs */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

////////// Approach -1)

int maxProductDifference(vector<int> &nums)
{
    int n = nums.size();
    int largest = INT_MIN, sec_largest = INT_MIN;
    int minimum = INT_MAX, sec_minimum = INT_MAX;

    for (auto &element : nums)
    {
        if (element > largest)
        {
            sec_largest = largest;
            largest = element;
        }
        else
            sec_largest = max(sec_largest, element);

        if (element < minimum)
        {
            sec_minimum = minimum;
            minimum = element;
        }
        else
            sec_minimum = min(sec_minimum, element);
    }
    return ((largest * sec_largest) - (minimum * sec_minimum));
}

/////////// Approach -2)

int maxProductDifference(vector<int> &nums)
{
    int n = nums.size();
    sort(all(nums));

    int x = nums[n - 1], y = nums[n - 2];
    int w = nums[0], z = nums[1];

    return x * y - w * z;
}

int main()
{
    return 0;
}