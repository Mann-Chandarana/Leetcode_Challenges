/*-------- Hard -----------*/

/*- Parsing A Boolean Expression -*/

//////// Question number 1106.

#include <bits/stdc++.h>
using namespace std;

bool parseBoolExpr(string expression)
{
    vector<bool> res;
    stack<char> st;
    int n = expression.length();

    for (int i = n - 1; i > 0; i--)
    {
        char chara = expression[i];
        if (chara == ',')
        {
            continue;
        }
        else if (chara == ')')
        {
            st.push(chara);
        }
        else if (chara == 't' || chara == 'f')
        {
            st.push(chara);
        }
        else if (chara == '(')
        {
            char symbol = expression[i - 1];
            i--;
            while (st.top() != ')')
            {
                if (st.top() == 't')
                {
                    res.push_back(1);
                }
                else if (st.top() == 'f')
                {
                    res.push_back(0);
                }
                st.pop();
            }
            st.pop();
            if (symbol == '&')
            {
                bool mutex = true;
                for (auto element : res)
                {
                    mutex &= element;
                }
                mutex ? st.push('t') : st.push('f');
            }
            else if (symbol == '|')
            {
                bool mutex = false;
                for (auto element : res)
                {
                    mutex |= element;
                }
                mutex ? st.push('t') : st.push('f');
            }
            else if (symbol == '!')
            {
                bool element = res[0];
                element ? st.push('f') : st.push('t');
            }
            res.erase(res.begin(), res.end());
        }
    }
    
    return st.top() == 't';
}

int main()
{
    string expression = "!(&(f,t))";
    cout << parseBoolExpr(expression) << endl;
    return 0;
}