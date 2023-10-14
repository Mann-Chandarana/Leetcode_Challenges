/*--------  Medium --------*/

/*- Evaluate Reverse Polish Notation -*/

//////// Question number 150.

#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<long long> st;
    for (auto letter : tokens)
    {
        if (letter == "+" || letter == "-" || letter == "*" || letter == "/")
        {
            long long num1 = st.top();
            st.pop();

            long long num2 = st.top();
            st.pop();

            char charac = letter[0];
            switch (charac)
            {
            case '+':
                st.push(num2 + num1);
                break;

            case '-':
                st.push(num2 - num1);
                break;

            case '*':
                st.push(num2 * num1);
                break;
            case '/':
                st.push(num2 / num1);
                break;

            default:
                break;
            }
        }
        else
        {
            long long num = stoi(letter);
            st.push(num);
        }
    }
    return st.top();
}

int main()
{
    vector<string> tokens = {"-128","-128","*","-128","*","-128","*","8","*","-1","*"};
    cout << evalRPN(tokens) << endl;
    return 0;
}