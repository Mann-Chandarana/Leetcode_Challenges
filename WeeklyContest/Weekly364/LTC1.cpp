/* 8048. Maximum Odd Binary Number */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

string maximumOddBinaryNumber(string s)
{
    int n = s.length();

    int no_ones = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            no_ones++;
    }

    string ans(n, ' ');

    if (no_ones >= 1)
        ans[n - 1] = '1', no_ones--;

    int i = 0;
    while (no_ones--)
        ans[i++] = '1';

    return ans;
}

int main()
{
    return 0;
}