/*--------Medium-----------*/

/*- Frequency of the most frequent element -*/

//////// Question number 1838.

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxFrequency(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    ll i = 0, j = 0, sum = 0, max_len = INT_MIN;

    while (j < nums.size())
    {
        sum += nums[j];
        if (nums[j] * (j - i + 1) - sum <= k)
        {
            max_len = max(max_len, j - i + 1);
        }
        else
        {
            sum -= nums[i];
            i++;
        }
        j++;
    }
    return max_len;
}

int main()
{
    vector<int> nums = {1, 4, 8, 13};
    cout << maxFrequency(nums, 5) << endl;
    return 0;
}