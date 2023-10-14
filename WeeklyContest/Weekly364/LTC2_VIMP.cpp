/*-------- Medium -----------*/

/*- Beautiful Towers I -*/

//////// Question number 100049.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/***** Question -1) *****/

ll maximumSumOfHeights(vector<int> &maxHeights)
{
    int n = maxHeights.size();

    /*** Part-1 ****/

    vector<int> prevSmallest(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and maxHeights[st.top()] >= maxHeights[i])
            st.pop();

        if (!st.empty())
            prevSmallest[i] = st.top();

        st.push(i);
    }

    /*** Part-2 ****/

    vector<int> nextSmallest(n, n);
    st = stack<int>();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and maxHeights[st.top()] >= maxHeights[i])
            st.pop();

        if (!st.empty())
            nextSmallest[i] = st.top();

        st.push(i);
    }

    /*** Part-3 ****/

    vector<ll> leftSum(n, 0);
    leftSum[0] = maxHeights[0];

    for (int i = 1; i < n; i++)
    {
        int smalleridx = prevSmallest[i];
        int count = i - smalleridx;

        leftSum[i] = (count * (1LL) * maxHeights[i]);

        if (smalleridx != -1)
            leftSum[i] += leftSum[smalleridx];
    }

    /*** Part-4 ****/

    vector<ll> rightSum(n, 0);
    rightSum[n - 1] = maxHeights[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        int smalleridx = nextSmallest[i];
        int count = smalleridx-i;

        rightSum[i] = (count * 1LL * maxHeights[i]);

        if (smalleridx != n)
            rightSum[i] += rightSum[smalleridx];
    }

    /*** Final Portion ****/

    ll maxSum = 0;

    for (int i = 0; i < n; i++)
    {
        ll totalSum = rightSum[i] + leftSum[i] - maxHeights[i];
        maxSum = max(maxSum, totalSum);
    }

    return maxSum;
}

/***** Question - 2) *****/

ll maxiSum(vector<int> &maxHeights, int index, int &n)
{
    int min_element = maxHeights[index];
    ll sum = 0;

    for (int i = index; i >= 0; i--)
    {
        min_element = min(min_element, maxHeights[i]);
        sum += min_element;
    }

    min_element = maxHeights[index];

    for (int i = index + 1; i < n; i++)
    {
        min_element = min(min_element, maxHeights[i]);
        sum += min_element;
    }

    return sum;
}

ll maximumSumOfHeights(vector<int> &maxHeights)
{
    ll max_sum = LONG_MIN;
    int n = maxHeights.size();

    for (int i = 0; i < n; i++)
        max_sum = max(max_sum, maxiSum(maxHeights, i, n));

    return max_sum;
}

int main()
{
    vector<int> maxHeights = {3, 6, 3, 5, 5, 1, 2, 5, 5, 6};
    // {3,6,3,3,3,1,1,1,1,1}
    //{1,1,1,1,1,1,2,5,5,6}
    cout << maximumSumOfHeights(maxHeights) << endl;

    return 0;
}