/* 6439. Minimum String Length After Removing Substrings */

#include <bits/stdc++.h>
using namespace std;

int minLength(string s)
{
    if (s.length() == 0)
        return 0;

    stack<char> st;
    st.push(s[0]);

    for (int i = 1; i < s.length(); i++)
    {
        if (!st.empty() and (st.top() == 'A' and s[i] == 'B' || st.top() == 'C' and s[i] == 'D'))
            st.pop();

        else
            st.push(s[i]);
    }
    return st.size();
}

int main()
{
    string str = "";
    cout << minLength("ACBBD") << endl;
    return 0;
}