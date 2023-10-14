/*-------- Medium -----------*/

/*- Lexicographically Smallest String After Substring Operation -*/

//////// Question number 6465.

#include <bits/stdc++.h>
using namespace std;

string smallestString(string s)
{
    int i = 0, n = s.length();
    while (i < n && s[i] == 'a')
        i++;
    if (i == n)
    {
        s[n - 1] = 'z';
        return s;
    }
    while (i < n && s[i] != 'a')
    {
        s[i]--;
        i++;
    }
    return s;
}

int main()
{
    return 0;
}