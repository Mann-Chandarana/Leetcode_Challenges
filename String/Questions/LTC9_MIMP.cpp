/*--------  Medium --------*/

/*- Decoded String at Index -*/

//////// Question number 880.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

string decodeAtIndex(string s, int k)
{
    int n = s.length();

    ll size = 0;

    for (char ch : s)
    {
        if (isdigit(ch))
            size = size * (ch - '0');
        else
            size += 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        k = k % size;

        if (k == 0 and isalpha(s[i]))
            return string(1, s[i]);

        if (isalpha(s[i]))
            size -= 1;
        else
            size = size / (s[i] - '0');
    }

    return "";
}

int main()
{
    return 0;
}