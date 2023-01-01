/* 125. Valid Palindrome */

#include <bits/stdc++.h>
using namespace std;

bool solve(string s, int i, int n)
{
    if (i == (s.length() / 2))
    {
        return true;
    }

    if (s[i] == s[n - i] and solve(s, i + 1, n))
    {
        return true;
    }
    return false;
}

bool isPalindrome(string s)
{
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (isalnum(s[i]))
        {
            str.push_back(tolower(s[i]));
        }
    }

    int n = str.length();
    return solve(str, 0, n - 1);
}

int main()
{
    cout << isPalindrome("0P") << endl;
    return 0;
}