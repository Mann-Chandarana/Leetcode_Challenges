/*-------- Medium -----------*/

/*- Minimum Add to Make Parentheses Valid  -*/

//////// Question number 921.

#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s)
{
    int open = 0, operation = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            open++;

        else if (s[i] == ')')
        {
            open--;
            if (open < 0)
                open = 0, operation++;
        }
    }

    while (open)
    {
        open--, operation++;
    }

    return operation;
}

int main()
{
    return 0;
}