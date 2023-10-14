/*
1) Postfix to Prefix
2) Prefix to Postfix
*/

#include <bits/stdc++.h>
using namespace std;

/* Postfix to prefix */

bool isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

string postToPre(string post_exp)
{
    stack<string> s;

    int length = post_exp.size();

    for (int i = 0; i < length; i++)
    {
        if (isOperator(post_exp[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = post_exp[i] + op2 + op1;

            s.push(temp);
        }

        else
            s.push(string(1, post_exp[i]));
    }

    string ans = "";
    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    return ans;
}

/* Prefix to Postfix */

bool isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

// Convert prefix to Postfix expression
string preToPost(string pre_exp)
{

    stack<string> s;
    int length = pre_exp.size();

    for (int i = length - 1; i >= 0; i--)
    {
        if (isOperator(pre_exp[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = op1 + op2 + pre_exp[i];
            s.push(temp);
        }

        else
        {
            s.push(string(1, pre_exp[i]));
        }
    }

    return s.top();
}

int main()
{
    return 0;
}