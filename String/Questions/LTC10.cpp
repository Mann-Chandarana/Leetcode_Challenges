// 557. Reverse Words in a String III

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/* Approach -1) */

string reverseWords(string s)
{
    int n = s.length(), prev = 0;

    for (int i = 0; i <= n; i++)
    {
        if (s[i] == '\0' or (i < n and s[i] == ' '))
        {
            int p1 = prev, p2 = i - 1;
            while (p1 < p2)
                swap(s[p1++], s[p2--]);
            prev = i + 1;
        }
    }
    return s;
}

/* Approach -2) */

string reverseWords(string s)
{
    int n = s.length();
    stack<char> st;
    string answer = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            while (!st.empty())
            {
                answer += st.top();
                st.pop();
            }
            answer += " ";
        }
        else
            st.push(s[i]);
    }
    while (!st.empty())
    {
        answer += st.top();
        st.pop();
    }
    return answer;
}

int main()
{
    return 0;
}