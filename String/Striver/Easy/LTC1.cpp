// 1021. Remove Outermost Parentheses

#include <bits/stdc++.h>
using namespace std;

/* Using Stacks  */

string removeOuterParentheses(string s)
{
    stack<char> st;

    int n = s.length();
    string ans;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            if (!st.empty())
                ans += s[i];
            st.push(s[i]);
        }
        else
        {
            if (st.size() > 1)
                ans += s[i], st.pop();
        }
    }

    return ans;
}

/* Without using stacks */

string removeOuterParentheses(string s)
{
    int n = s.size();
    string p;
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            c++;

        else if (s[i] == ')')
            c--;
        
        /*
        1) c=1 means it is the first opening bracket
        2) c=0 means it is the last closed bracket so we have to ignore it 
        */

        if ((c > 1 and s[i] == '(') or (c > 0 and s[i] == ')'))
            p += s[i];
    }
    return p;
}

int main()
{
    cout << removeOuterParentheses("((()())(()()))") << endl;
    return 0;
}