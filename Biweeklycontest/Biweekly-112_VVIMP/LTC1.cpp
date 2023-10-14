/* 2839. Check if Strings Can be Made Equal With Operations I */

#include <bits/stdc++.h>
using namespace std;

bool canBeEqual(string s1, string s2)
{
    int n = s1.length(), m = s2.length();

    if (n != m)
        return false;

    for (int i = 0; i < n / 2; i++)
    {
        if ((s1[i] != s2[i] || s1[i] != s2[i + 2]) and (s1[i + 2] != s2[i] || s1[i + 2] != s2[i + 2]))
            return false;
    }

    return true;
}

int main()
{
    return 0;
}