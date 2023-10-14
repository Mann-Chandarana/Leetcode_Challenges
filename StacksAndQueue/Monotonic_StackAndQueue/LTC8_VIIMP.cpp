/*--------  Hard --------*/

/*- Sum of Subarray Minimums -*/

//////// Question number 907


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> getNSL(vector<int> arr)
{
    vector<int> result(arr.size());
    stack<int> st;

    for (int i = 0; i < arr.size(); i++)
    {
        if (st.empty())
            result[i] = -1;

        else
        {
            while (!st.empty() and arr[st.top()] >= arr[i])
                st.pop();

            result[i] = st.empty() ? -1 : st.top();
        }
        st.push(i);
    }

    return result;
}

vector<int> getNSR(vector<int> arr)
{
    int n = arr.size();
    vector<int> result(arr.size());
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
            result[i] = n;

        else
        {
            while (!st.empty() and arr[st.top()] > arr[i])
                st.pop();

            result[i] = st.empty() ? n : st.top();
        }
        st.push(i);
    }

    return result;
}

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();

    vector<int> NSL = getNSL(arr);
    vector<int> NSR = getNSR(arr);

    ll sum = 0, answer = 0;
    int M = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
        ll ls = i - NSL[i];
        ll rs = NSR[i] - i;

        ll totalways = ls * rs;
        ll totalsum = arr[i] * totalways;

        sum = (sum + totalsum) % M;
    }

    return sum;
}

int main()
{
    return 0;
}