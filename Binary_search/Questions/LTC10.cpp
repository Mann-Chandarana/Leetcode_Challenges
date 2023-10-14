/*--------  Medium --------*/

/*- Minimum Cost to Make Array Equal -*/

//////// Question number 2448.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long find_cost(vector<int> &nums, vector<int> &cost, int val)
{
    ll answer = 0;

    for (int i = 0; i < nums.size(); i++)
        answer += (abs(nums[i] - val) * cost[i]);

    return answer;
}

long long minCost(vector<int> &nums, vector<int> &cost)
{
    ll low = *min_element(nums.begin(), nums.end());
    ll high = *max_element(nums.begin(), nums.end());

    ll answer = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        ll cost1 = find_cost(nums, cost, mid);
        ll cost2 = find_cost(nums, cost, mid + 1);

        answer = min(cost1, cost2);

        if (cost2 > cost1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return answer == INT_MAX ? 0 : answer;
}

int main()
{
    return 0;
}