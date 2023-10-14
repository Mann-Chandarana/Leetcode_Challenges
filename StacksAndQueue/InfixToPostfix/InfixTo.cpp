#include <bits/stdc++.h>
using namespace std;

/* Infix To Postfix */

int prec(char c)
{
    if (c == '^')
        return 3;

    else if (c == '/' || c == '*')
        return 2;

    else if (c == '+' || c == '-')
        return 1;

    else
        return -1;
}

void infixTopostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if ((c >= 'a' and c <= 'z') || (c >= 'A' and c <= 'Z') || (c >= '0' and c <= '9'))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() and st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() and prec(s[i]) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    cout << "Prefix expression : " << result << endl;
}

/* Infix to Prefix */

int pred(char ch)
{
    if (ch == '^')
        return 3;

    else if (ch == '/' || ch == '*')
        return 2;

    else if (ch == '+' || ch == '-')
        return 1;

    return -1;
}

string infixToPrefix(string s)
{
    int n = s.length();
    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            s[i] = ')';

        else if (s[i] == ')')
            s[i] = '(';
    }

    stack<char> st;
    string result = "";

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        if ((ch >= 'a' and ch <= 'z') || (ch >= 'A' and ch <= 'Z') || (ch >= '0' and ch <= '9'))
        {
            result += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }

        else if (ch == ')')
        {
            while (!st.empty() and st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() and pred(ch) <= pred(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    return 0;
}