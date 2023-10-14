/*-------- Hard -----------*/

/*- Longest Happy Prefix -*/

//////// Question number 1392.

#include <bits/stdc++.h>
using namespace std;

string longestPrefix(string s)
{
    int n = s.size();

    vector<int> lps(n, 0);

    lps[0] = 0;

    int i = 1, len = 0;

    int maxi = 0;

    while (i < n)
    {
        if (s[len] == s[i])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
                len = lps[len - 1];
        }
    }
    if (lps[n - 1] == 0)
        return "";

    return s.substr(0, lps[n - 1]);
}

int main()
{
    cout << longestPrefix("bba") << endl;
    return 0;
}