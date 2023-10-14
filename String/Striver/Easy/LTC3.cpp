/* 1903. Largest Odd Number in String */

#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num)
{
    int n = num.length();
    string ans = "";

    int i;
    for (i = n - 1; i >= 0; i--)
    {
        if ((num[i] - '0') & 1)
            break;
        num.pop_back();
    }
    return num;
}

int main()
{
    return 0;
}