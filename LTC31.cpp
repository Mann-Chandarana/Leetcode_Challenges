#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

bool checkPalindrome(int i, int j, string s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

int countSubstrings(string s)
{
    int n = s.length();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev <= i - 1; prev++)
        {
            if (checkPalindrome(i, j, s))
                count++;
        }
    }
    return count;
}

int main()
{
    return 0;
}