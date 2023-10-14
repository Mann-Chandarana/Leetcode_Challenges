/*--------  Medium --------*/

/*- Minimum Operations to Form Subsequence With Target Sum -*/

//////// Question number 2835.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/* Using Bitmanipulation */

int minOperations(vector<int> &nums, int target)
{
    vector<int> BitsArr(31, 0);
    ll total = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int x = nums[i];
        BitsArr[int(log2(x))]++;
        total += x;
    }

    if (total < target)
        return -1;

    int i = 0, operations = 0;

    while (i < 30)
    {
        if ((1 << i) & target)
        {
            if (BitsArr[i] > 0)
                BitsArr[i]--;
            else
            {
                int j = i;

                while (j < 30 and BitsArr[j] == 0)
                {
                    j++;
                    operations++;
                }
                BitsArr[j]--;
                while (j > i)
                    BitsArr[--j]++;
            }
        }
        BitsArr[i + 1] += BitsArr[i] / 2;
        i++;
    }
    return operations;
}

/* Without using bitmanipulation */

int minOperations(vector<int> &nums, int target)
{
    ll total = 0;
    ll sum = accumulate(all(nums), total);

    if (sum < target)
        return -1;

    sort(all(nums));
    ll operation = 0;

    while (target > 0)
    {
        int a = nums.back();
        nums.pop_back();

        if (sum - a >= target)
            sum -= a;
        else if (a <= target)
        {
            sum -= a;
            target -= a;
        }
        else
        {
            nums.push_back(a / 2);
            nums.push_back(a / 2);
            operation++;
        }
    }

    return target == 0 ? operation : -1;
}

int main()
{
    vector<int> nums = {16, 16, 4};
    cout << minOperations(nums, 3) << endl;
    return 0;
}