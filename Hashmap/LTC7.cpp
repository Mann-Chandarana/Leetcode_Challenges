/*--------Hard-----------*/

/*- Data Stream as Disjoint Intervals -*/

//////// Question number 352.

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity - O(nlogn)
Space complexity -O(N)
*/

class SummaryRanges
{
public:
    unordered_set<int> st;

    SummaryRanges()
    {
        st.clear();
    }

    void addNum(int value)
    {
        st.insert(value);
    }

    vector<vector<int>> getIntervals()
    {
        vector<int> nums(begin(st), end(st));

        sort(begin(nums), end(nums));

        vector<vector<int>> result;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int left = nums[i];

            while (i < n - 1 and nums[i] + 1 == nums[i + 1])
            {
                i++;
            }
            result.push_back({left, nums[i]});
        }
        return result;
    }
};

class SummaryRanges
{
public:
    map<int, int> mp;

    SummaryRanges()
    {
        mp.clear();
    }

    void addNum(int value)
    {
        int left = value, right = value;

        auto just_bada = mp.upper_bound(value);
        if (just_bada != mp.begin())
        {
            auto just_peeche = just_bada;
            just_peeche--;

            if (just_peeche->second >= value)
            {
                return;
            }

            if (just_peeche->second == value - 1)
            {
                left = just_peeche->first;
            }
        }

        if (just_bada != mp.end() and just_bada->first == value + 1)
        {
            right = just_bada->second;
            mp.erase(just_bada);
        }
        mp[left] = right;
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> result;

        for (auto it : mp)
        {
            result.push_back({it.first, it.second});
        }

        return result;
    }
};

int main()
{
    return 0;
}