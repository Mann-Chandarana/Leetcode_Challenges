/*- Set mismatch -*/

//////// Question number 645.

#include <bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int> &nums)
{
    vector<int> ans;
    sort(nums.begin(), nums.end());

    int initial_sum = 0, n = nums.size();

    for (auto element : nums)
    {
        initial_sum += element;
    }
    set<int> s;

    for (int element : nums)
    {
        s.insert(element);
    }
    int sum = accumulate(s.begin(), s.end(), 0);

    int repeated = initial_sum - sum;
    int missing = (n * (n + 1) / 2) - sum;

    return {repeated, missing};
}

int main()
{
    vector<int> nums = {1,2,2,4};
    nums = findErrorNums(nums);

    for (auto element : nums)
    {
        cout << element << " ";
    }
    return 0;
}