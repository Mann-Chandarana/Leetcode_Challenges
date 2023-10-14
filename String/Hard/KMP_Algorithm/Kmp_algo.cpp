/* KMP String matching algorithm */

#include <bits/stdc++.h>
using namespace std;

vector<int> FillLps(string needle)
{
    int n = needle.size();
    vector<int> lps(n, 0);
    lps[0] = 0;

    int i = 1, len = 0;

    while (i < n)
    {
        if (needle[len] == needle[i])
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
}

int strStr(string haystack, string needle)
{
    int n = haystack.size();
    int m = needle.size();

    vector<int> lps = FillLps(needle);

    int i = 0, j = 0;

    while (i < n)
    {
        if (haystack[i] == needle[j])
        {
            i++, j++;
            if (j == m)
                return i - j;
        }
        else if (i < n and haystack[i] != needle[j])
        {
            if (j == 0)
                i++;

            else
                j = lps[j - 1];
        }
    }
    return -1;
}

int main()
{
    return 0;
}