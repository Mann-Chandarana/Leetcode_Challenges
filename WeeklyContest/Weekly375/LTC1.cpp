/* 100143. Count Tested Devices After Test Operations */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int countTestedDevices(vector<int> &batteryPercentages)
{
    int n = batteryPercentages.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (batteryPercentages[i] - cnt > 0)
            cnt++;
    }
    return cnt;
}

int main()
{
    return 0;
}