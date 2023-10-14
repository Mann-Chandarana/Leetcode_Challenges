/*1544 . Make The String Great*/

#include <bits/stdc++.h>
using namespace std;

// string makeGood(string s)
// {
//     int i = 0;
//     while (i < s.length())
//     {
//         if (i + 1 < s.length() and (s[i] - s[i + 1] == 32 || s[i] - s[i + 1] == -32))
//         {
//             s.erase(s.begin() + i, s.begin() + i + 2);
//             i = 0;
//         }
//         else
//         {
//             i++;
//         }
//     }
//     return s;
// }

string makeGood(string s)
{
    string answer = "";
    stack<int> st;
    int i = 0;
    while (i < s.length())
    {
        if (st.empty() and i < s.length())
        {
            st.push(s[i++]);
        }
        else
        {
            (st.top() - s[i] == 32 || st.top() - s[i] == -32) ? st.pop() : st.push(s[i]);
            i++;
        }
    }

    while (!st.empty())
    {
        answer.push_back(st.top());
        st.pop();
    }

    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    return 0;
}