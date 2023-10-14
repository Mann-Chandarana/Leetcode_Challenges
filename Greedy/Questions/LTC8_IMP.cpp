#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define pii pair<int, int>

int minTaps(int n, vector<int> &ranges)
{
    vector<pii> water(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        if (i - ranges[i] <= 0 && n <= i + ranges[i])
            return 1;

        water[i] = {i - ranges[i], i + ranges[i]};
    }
    std::sort(water.begin(), water.end());

    if (water[0].first > 0)
        return -1;

    pii curr = water[0];
    int prevEnd = curr.second;
    int taps = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (curr.second < water[i].first)
            return -1;
        if (water[i].second <= curr.second)
            continue;

        if (curr.first == water[i].first || water[i].first <= 0)
        {
            curr = water[i];
            prevEnd = curr.second;
        }
        else
        {
            cout << prevEnd << " Hello" << endl;
            if (prevEnd < water[i].first)
            {
                prevEnd = curr.second;
                taps += 1;
            }
            curr.second = water[i].second;
        }
        if (curr.second >= n)
            break;
    }

    return taps + 1;
}

int minTaps(int n, vector<int> &ranges)
{
    vector<int> arr(n + 1, 0);

    for (int i = 0; i < ranges.size(); i++)
    {
        int start = max(0, i - ranges[i]);
        int end = min(n, i + ranges[i]);

        arr[start] = max(arr[start], end);
    }

    int taps = 0, currEnd = 0, maxEnd = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i > maxEnd)
            return -1;

        if (i > currEnd)
        {
            taps++;
            currEnd = maxEnd;
        }

        maxEnd = max(maxEnd, arr[i]);
    }
    return taps;
}

int main()
{
    vector<int> ranges = {0, 5, 0, 3, 3, 3, 1, 4, 0, 4};
    cout << minTaps(9, ranges) << endl;
    return 0;
}