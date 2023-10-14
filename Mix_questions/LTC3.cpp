/*-------- Hard -----------*/

/*- Minimize Deviation in Array -*/

//////// Question number 1675.

#include <bits/stdc++.h>
using namespace std;

/** Using ordered set **/

int minimumDeviation(vector<int> nums)
{
    set<int> st;

    for (auto &element : nums)
    {
        if (element % 2 != 0)
        {
            element *= 2;
        }
        st.insert(element);
    }

    int diff = *st.rbegin() - *st.begin();

    while ((*st.rbegin()) % 2 == 0)
    {
        int temp = *st.rbegin();
        st.erase(temp);
        temp /= 2;
        st.insert(temp);

        diff = min(diff, *st.rbegin() - *st.begin());
    }
    return diff;
}

/** Using priority queue **/

int minimumDeviation(vector<int> &nums)
{
    int n = nums.size(), mini = INT_MAX;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 != 0)
            nums[i] *= 2;

        pq.push(nums[i]);
        mini = min(mini, nums[i]);
    }
    int diff = INT_MAX;

    while (pq.top() % 2 == 0)
    {
        int maxi = pq.top();
        pq.pop();

        diff = min(maxi - mini, diff);
        mini = min(mini, maxi / 2);
        pq.push(maxi / 2);
    }

    return min(diff, pq.top() - mini);
}

int main()
{
    return 0;
}