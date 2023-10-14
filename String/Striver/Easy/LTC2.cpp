/*-------- Medium -----------*/

/*- Reverse Words in a String -*/

//////// Question number 151.

#include <bits/stdc++.h>
using namespace std;

/* Using Stacks */

string reverseWords(string s)
{
    string temp = "";
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == ' ')
        {
            if (temp != "")
                st.push(temp);
            temp = "";
        }

        else
            temp += ch;
    }

    if (temp != "")
    {
        st.push(temp);
    }
    string ans = "";

    while (!st.empty())
    {
        ans += (st.top() + " ");
        st.pop();
    }
    ans.pop_back();

    return ans;
}

/* Without using stacks */

string reverseWords(string s)
{
    int len = s.length();

    string currWord = "";

    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
            currWord = s[i] + currWord;
        else
        {
            if (currWord != "")
                s += " " + currWord;

            currWord = "";
        }
    }

    if (currWord != "")
        s += " " + currWord;

    s.substr(len + 1);
}

int main()
{
    return 0;
}