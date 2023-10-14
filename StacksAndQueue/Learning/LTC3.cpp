/*- Valid Parentheses -*/

//////// Question number 20.

#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // if opening bracket then push into the stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }

        else
        {
            if (!st.empty())
            {
                char top = st.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                    st.pop();

                else
                    return false;
            }
            else
                return false;
        }
    }

    if (st.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    return 0;
}