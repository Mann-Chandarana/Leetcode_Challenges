/*--------  Medium --------*/

/*- Maximum Number of Alloys -*/

//////// Question number 2861.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) v.begin(), v.end()

bool is_ok(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost, int x, vector<int> &comp)
{

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += max(((x * 1LL * comp[i]) - stock[i]), 0LL) * cost[i];
    }
    return sum <= budget;
}

int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost)
{
    ll ans = 0;

    for (auto comp : composition)
    {
        ll l = 0, r = 1e9, res = 0;

        while (l <= r)
        {
            ll mid = l + (r - l) / 2;

            if (is_ok(n, k, budget, composition, stock, cost, mid, comp))
            {
                res = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        ans = max(ans, res);
    }
    return (int)ans;
}

int main()
{
    return 0;
}