/* 28. Find the Index of the First Occurrence in a String */

#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    int  j = 0;
    int pi = 0;

    while (j < haystack.length())
    {
        if (haystack[j] == needle[pi])
        {
            pi++;
            if (pi == needle.length())
                return j+1-needle.length();
        }
        else
        {
            if (pi != 0)
            {
                j-=pi;;
                pi = 0;
            }
        }
        j++;
    }
    return -1;
}

int main()
{
    cout << strStr("mississippi", "pi") << endl;
    return 0;
}