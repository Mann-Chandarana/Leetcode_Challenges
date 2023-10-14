/*--------  Medium --------*/

/*- Next Greater Element II -*/

//////// Question number 503.

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> v(n, -1);

    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() and nums[i % n] >= st.top())
            st.pop();

        if (!st.empty() and i < n)
            v[i] = st.top();

        st.push(nums[i % n]);
    }
    return v;
}

int main()
{
    return 0;
}