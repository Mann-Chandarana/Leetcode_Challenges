/*--------  Medium --------*/

/*- Make String a Subsequence Using Cyclic Increments -*/

//////// Question number 8014.

#include <bits/stdc++.h>
using namespace std;

bool canMakeSubsequence(string str1, string str2)
{
    int i = 0, j = 0;
    int n = str1.length(), m = str2.length();
    if (n < m)
        return false;

    while (i < n and j < m)
    {
        if ((str1[i] == str2[j]) || (str1[i] + 1 == str2[j]) || (str1[i] == 'z' and str2[j] == 'a'))
            j++;

        i++;
    }
    return j == m;
}

int main()
{
    return 0;
}