/* 
1) Prefix to infix
2) Postfix to infix
 */

#include <bits/stdc++.h>
using namespace std;

/* Prefix to infix */

bool isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
    case '^':
    case '%':
        return true;
    }
    return false;
}

string preToInfix(string pre_exp)
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

            string temp = "(" + op1 + pre_exp[i] + op2 + ")";

            s.push(temp);
        }

        else
        {
            s.push(string(1, pre_exp[i]));
        }
    }

    return s.top();
}

/* Postfix to infix */

bool isOperand(char x)
{
    return (x >= 'a' && x <= 'z') ||
           (x >= 'A' && x <= 'Z');
}

string getInfix(string exp)
{
    stack<string> s;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (isOperand(exp[i]))
        {
            string op(1, exp[i]);
            s.push(op);
        }

        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] +
                   op1 + ")");
        }
    }

    return s.top();
}

int main()
{
    return 0;
}