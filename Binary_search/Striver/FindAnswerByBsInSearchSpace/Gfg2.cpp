/* Geeks for Geeks :-  Aggressive cows  */

#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int> &stalls, int n, int mid, int k)
{
    int coordinate = stalls[0], cnt = 1;

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - coordinate >= mid)
        {
            coordinate = stalls[i];
            cnt++;
        }
        if (cnt == k)
            return true;
    }
    return false;
}

int solve(int n, int k, vector<int> &stalls)
{
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[n - 1] - stalls[0], ans = 0;

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (canPlace(stalls, n, mid, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    return 0;
}