// 1710. Maximum Units on a Truck

#include <bits/stdc++.h>
using namespace std;

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
    vector<pair<int, int>> mp;
    int ans = 0;

    for (int i = 0; i < boxTypes.size(); i++)
        mp.push_back(make_pair(boxTypes[i][1], boxTypes[i][0]));

    sort(mp.begin(), mp.end(), greater<pair<int, int>>());

    for (int i = 0; i < mp.size(); i++)
    {
        if (mp[i].second <= truckSize)
        {
            ans += mp[i].first * mp[i].second;
            truckSize -= mp[i].second;
        }
        else
        {
            ans += mp[i].first * truckSize;
            truckSize = 0;
            break;
        }
    }

    return ans;
}

int main()
{
    return 0;
}