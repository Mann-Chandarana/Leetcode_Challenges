/*-------- Medium -----------*/

/*- Make Array Strictly Increasing -*/

//////// Question number 1187.

#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> mp;
int solve(int index, vector<int> &arr1, vector<int> &arr2, int prev)
{
    if (index == arr1.size())
        return 0;

    if (mp.find({index, prev}) != mp.end())
        return mp[{index, prev}];

    int exclude = 1e9;
    if (arr1[index] > prev)
        exclude = solve(index + 1, arr1, arr2, index);

    int include = 1e9;

    auto greater_value = upper_bound(arr2.begin(), arr2.end(), prev);

    if (greater_value != arr2.end())
    {
        int i = greater_value - arr2.begin();
        include = 1 + solve(index + 1, arr1, arr2, arr2[i]);
    }

    return mp[{index, prev}] = min(include, exclude);
}

int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
{
    sort(begin(arr2), end(arr2));

    int result = solve(0, arr1, arr2, INT_MIN);

    if (result = 1e9)
        return -1;

    return result;
}

int main()
{
    return 0;
}