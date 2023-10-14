/*- Next Greater Element I -*/

//////// Question number 496.

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums2.size();
    stack<int> st;
    st.push(INT_MAX);

    vector<int> ans(n);
    unordered_map<int, int> mp;

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = nums2[i];

        while (st.top() <= curr)
            st.pop();

        mp[nums2[i]] = st.top() == INT_MAX ? -1 : st.top();
        st.push(curr);
    }
    vector<int> answer;
    for (auto i : nums1)
        answer.push_back(mp[i]);

    return answer;
}

int main()
{
    return 0;
}