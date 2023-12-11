/* 2264. Largest 3-Same-Digit Number in String */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

string largestGoodInteger(string num)
{
    int n = num.length();
    char maxch = ' ';

    for (int i = 2; i < n; i++)
    {
        if (num[i] == num[i - 1] and num[i] == num[i - 2])
            maxch = max(maxch, num[i]);
    }
    if (maxch ==' ')
        return " ";
    else
        return string(3, maxch);
}

int main()
{
    return 0;
}