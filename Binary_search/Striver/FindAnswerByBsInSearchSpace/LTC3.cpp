/* Geeks for Geeks :- Minimum Days to make M bouquets */

#include <bits/stdc++.h>
using namespace std;

bool canEvaluate(vector<int> &bloomDay, int mid, int m, int k)
{
    int n = bloomDay.size();
    int value = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] <= mid)
        {
            value++;
            if (value == k)
            {
                count++;
                value = 0;
            }
        }
        else
            value = 0;

        if (count >= m)
        {
            return true;
        }
    }
    return false;
}

int solve(int M, int K, vector<int> &bloomDay)
{
    int low = 0, high = *max_element(bloomDay.begin(), bloomDay.end()), ans = INT_MAX;
    if (M * K > bloomDay.size())
        return -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canEvaluate(bloomDay, mid, M, K))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    cout << solve(3, 2, bloomDay) << endl;
    return 0;
}