/*-------- Medium --------*/

/*- Count Subarrays Where Max Element Appears at Least K Times -*/

//////// Question number 100137.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

ll countSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    ll maxi = *max_element(all(nums));

    ll i = 0, j = 0, answer = 0, count = 0;

    while (j < n)
    {
        if (nums[j] == maxi)
            count++;

        if (count >= k)
        {
            while (count >= k)
            {
                answer += (n - j);
                if (nums[i] == maxi)
                    count--;
                i++;
            }
        }

        j++;
    }
    return answer;
}

int main()
{
    vector<int> nums = {28, 5, 58, 91, 24, 91, 53, 9, 48, 85, 16, 70, 91, 91, 47, 91, 61, 4, 54, 61, 49};
    cout << countSubarrays(nums, 1) << endl;
    return 0;
}