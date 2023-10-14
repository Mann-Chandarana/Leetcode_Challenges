/* 6454. Lexicographically Smallest Palindrome */

#include <bits/stdc++.h>
using namespace std;

string makeSmallestPalindrome(string s)
{
    int start = 0, end = s.length() - 1;

    while (start < end)
    {
        if (s[start] != s[end])
        {
            int val = min(s[start] - 'a', s[end] - 'a');
            s[start] = char('a' + val);
            s[end] = char('a' + val);
        }
        start++, end--;
    }
    return s;
}

int main()
{
    cout << makeSmallestPalindrome("seven") << endl;
    return 0;
}