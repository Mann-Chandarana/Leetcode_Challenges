/*-------- Hard -----------*/

/*- Minimum Replacements to Sort the Array -*/

//////// Question number 2366.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll minimumReplacement(vector<int> &nums)
{
    int n = nums.size();

    ll operations = 0;

    for (ll i = n - 2; i >= 0; i--)
    {
        if (nums[i] <= nums[i + 1])
            continue;

        ll parts = nums[i] / nums[i + 1];

        if (nums[i] % nums[i + 1] != 0)
            parts++;

        operations += (parts - 1);

        nums[i] = nums[i] / parts;
    }
    return operations;
}

int main()
{
    return 0;
}