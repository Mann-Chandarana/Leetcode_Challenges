/* Minimum Average difference */
//////// Question number 2256.

#include <bits/stdc++.h>
using namespace std;

int minimumAverageDifference(vector<int> &nums)
{
    long long n = nums.size();
    long long prev_sum = 0;
    vector<long long> prefix(n);

    for (long long i = 0; i < n; i++)
    {
        prefix[i] = nums[i] + prev_sum;
        prev_sum = prefix[i];
    }

    long long total_sum = prefix[n - 1];

    int min_value = INT_MAX, index = 0;
    long long avge;

    for (long long i = 0; i < n; i++)
    {
        if (i != (n - 1))
        {
            avge = abs((prefix[i] / (i + 1)) - ((total_sum - prefix[i]) / (n - i - 1)));
        }
        else
        {
            avge = (prefix[i] / (i + 1));
        }
        if (avge < min_value)
        {
            min_value = avge;
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<int> nums = {4, 2, 0};
    cout << minimumAverageDifference(nums) << endl;
    return 0;
}