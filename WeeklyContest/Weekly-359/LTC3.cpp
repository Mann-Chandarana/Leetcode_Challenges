#include <bits/stdc++.h>
using namespace std;

static bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] > b[0])
        return false;

    if (a[0] < b[0])
        return true;

    if (a[1] > b[1])
        return false;

    if (a[1] < b[1])
        return true;

    return a[2] > b[2];
}
int search_index(vector<vector<int>> &offers, int idx)
{
    int n = offers.size();
    int l = idx, r = n - 1;
    l++;

    int answer = -1;

    while (l <= r)
    {
        int mid = l + ((r - l) / 2);

        int start = offers[mid][0];

        if (start > offers[idx][1])
            answer = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    return answer;
}

int f(int i, vector<vector<int>> &offers, vector<int> &dp)
{
    if (i >= offers.size())
        return 0;

    if (dp[i] != -1)
        return dp[i];

    // not sell

    int idx = search_index(offers, i);
    int buy = offers[i][2] + f(idx, offers, dp);

    int not_buy = f(i + 1, offers, dp);
    return dp[i] = max(buy, not_buy);
}

int maximizeTheProfit(int n, vector<vector<int>> &offers)
{
    vector<int> dp(offers.size() + 1, -1);
    sort(offers.begin(), offers.end());

    return f(0, offers, dp);
}

int main()
{
    vector<vector<int>> offers = {{0, 0, 1}, {0, 2, 10}, {1, 3, 2}};
    maximizeTheProfit(5, offers);
    return 0;
}