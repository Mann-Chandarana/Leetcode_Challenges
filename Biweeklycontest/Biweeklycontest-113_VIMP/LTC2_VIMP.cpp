/*-------- Medium -----------*/

/*- Minimum Array Length After Pair Removals -*/

//////// Question number 2856.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/* Approach -1) */

int minLengthAfterRemovals(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    for (int i : nums)
        mp[i]++;

    int maxi = 0;

    for (auto it : mp)
        maxi = max(maxi, it.second);

    if (maxi <= (n / 2))
    {
        if (n % 2)
            return 1;
        else
            return 0;
    }
    return 2 * maxi - n;
}

/* Approach -2) */

int minLengthAfterRemovals(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    for (int i : nums)
        mp[i]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

    for (auto p : mp)
        pq.push({p.second, p.first});

    while (pq.size() > 1)
    {
        int num1 = pq.top().second;
        int val1 = pq.top().first;
        pq.pop();

        int num2 = pq.top().second;
        int val2 = pq.top().first;
        pq.pop();

        val1--, val2--;
        if (val1)
            pq.push({val1, num1});

        if (val2)
            pq.push({val2, num1});
    }
    int ans = 0;
    if (!pq.empty())
        ans = pq.top().first;

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 3, 3, 4};
    cout << minLengthAfterRemovals(nums) << endl;
    return 0;
}