////// Question of storing index in stack.

/*--------  Medium --------*/

/*- Daily Temperatures -*/

//////// Question number 739.

#include <bits/stdc++.h>
using namespace std;

/*
Time complexity :- O(N)
Space complexity :- O(1)
*/

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();

    vector<int> answer(n, 0);

    int hottest = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (temperatures[i] >= hottest)
        {
            hottest = temperatures[i];
            continue;
        }
        int days = 1;

        while (temperatures[i + days] <= temperatures[i])
            days += answer[i + days];

        answer[i] = days;
    }
    return answer;
}

/*
Time complexity :- O(N)
Space complexity :- O(N)
*/

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

int main()
{
    return 0;
}