////// Question of storing index in stack.

/*--------  Medium --------*/

/*- Daily Temperatures -*/

//////// Question number 739.

#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> &T)
{
    int n = T.size();
    stack<int> st;
    vector<int> answer(n, 0);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && T[st.top()] < T[i])
        {
            int j = st.top();
            st.pop();
            answer[j] = i - j;
        }

        st.push(i);
    }
    return answer;
}

vector<int> dailyTemperatures(vector<int> &T)
{
    int n = T.size();
    stack<int> st;
    st.push(n - 1);

    vector<int> answer(n,0);

    for (int i = n - 2; i >= 0; i--)
    {
        int value = T[i];
        while (!st.empty() and value >= T[st.top()])
        {
            st.pop();
        }
        if (!st.empty())
        {
            answer[i] = st.top() - i;
        }

        st.push(i);
    }
    return answer;
}

int main()
{
    return 0;
}