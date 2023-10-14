/* Hashing in strings */

#include <bits/stdc++.h>
using namespace std;

int findMatching(string text, string pat)
{
    int pi = 0;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == pat[pi])
        {
            pi++;
            if (pi == pat.length())
                return i + 1 - pat.length();
        }
        else
        {
            if (pi != 0)
                i--;
            pi = 0;
        }
    }
    return -1;
}

int main()
{
    cout<<findMatching("mississippi","issip")<<endl;
    return 0;
}