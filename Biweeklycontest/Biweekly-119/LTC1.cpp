/* 2956. Find Common Elements Between Two Arrays */

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

#define ll long long
#define all(v) v.begin(), v.end()

vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
{

    unordered_set<int> st(all(nums2));

    int size1 = 0, size2 = 0;

    for (int i = 0; i < nums1.size(); i++)
    {
        if (st.find(nums1[i]) != st.end())
            size1++;
    }

    st = unordered_set<int>(all(nums1));

    for (int i = 0; i < nums2.size(); i++)
    {
        if (st.find(nums2[i]) != st.end())
            size2++;
    }

    return {size1, size2};
}

int main()
{
    return 0;
}