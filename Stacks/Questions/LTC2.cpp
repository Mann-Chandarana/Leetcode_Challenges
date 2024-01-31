/*--------  Medium --------*/

/*- Evaluate Reverse Polish Notation -*/

//////// Question number 150.

#include <bits/stdc++.h>
using namespace std;

/************* Approach -1) *************/

bool isOperator(string str)
{
    if (str == "+" || str == "-" || str == "*" || str == "/")
        return true;

    return false;
}

int evalRPN(vector<string> &tokens)
{
    int n = tokens.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (isOperator(tokens[i]))
        {
            int val1 = st.top();
            st.pop();

            int val2 = st.top();
            st.pop();

            if (tokens[i] == "+")
                st.push(val1 + val2);
            else if (tokens[i] == "-")
                st.push(val1 - val2);
            else if (tokens[i] == "*")
                st.push(val1 * val2);
            else if (tokens[i] == "/")
                st.push(val1 / val2);
        }
        else
            st.push(stoi(tokens[i]));
    }
    return st.top();
}

/************* Approach -2) *************/

int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    int result = 0;

    unordered_map<string, function<int(int, int)>> mp = {
        {"+", [](int a, int b)
         { return a + b; }},
        {"-", [](int a, int b)
         { return a - b; }},
        {"*", [](int a, int b)
         { return (long)a * (long)b; }},
        {"/", [](int a, int b)
         { return a / b; }},
    };

    for (const string &s : tokens)
    {
        if (s == "+" || s == "-" || s == "*" || s == "/")
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            result = mp[s](a, b);
            st.push(result);
        }
        else
            st.push(stoi(s));
    }
    return st.top();
}

int main()
{
    vector<string> tokens = {"-128", "-128", "*", "-128", "*", "-128", "*", "8", "*", "-1", "*"};
    cout << evalRPN(tokens) << endl;
    return 0;
}