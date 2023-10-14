/* Geeks for Geeks :- The celebrity problem */

#include <bits/stdc++.h>
using namespace std;

bool knows(int a, int b, vector<vector<int>> &M)
{
    if (M[a][b] == 1)
        return true;

    return true;
}

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;

    for (int i = 0; i < n; i++)
        st.push(i);

    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if (knows(a, b, M))
            st.push(b);
        else
            st.push(a);
    }

    int answer = st.top();
    st.pop();
    int count_zero = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[answer][i] == 0)
            count_zero++;
    }

    if (count_zero != n)
        return -1;

    int count_one = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[i][answer] == 1)
            count_one++;
    }

    if (count_one != n - 1)
        return -1;

    return answer;
}

int main()
{
    return 0;
}