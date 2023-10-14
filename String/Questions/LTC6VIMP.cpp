/* 459. Repeated Substring Pattern */

#include <bits/stdc++.h>
using namespace std;

/* O(N) */

bool repeatedSubstringPattern(string str)
{
    return (str + str).find(str, 1) < str.size();
}

/* O(n*√n)*/ 

bool repeatedSubstringPattern(string s)
{
    int n = s.length();
    string str = "";

    for (int l = 1; l <= n / 2; l++)
    {
        if (n % l == 0)
        {
            int times = n / l;
            string str = s.substr(0, l);

            string final = "";

            while (times--)
                final += str;

            if (final == s)
                return true;
        }
    }
    return false;
}

/* O(N√N) */

bool repeatedSubstringPattern(string s)
{
    int n = s.length();
    string str = "";

    for (int i = 0; i < n - 1; i++)
    {
        str += s[i];
        int l = str.length();

        if (n % l == 0)
        {
            int times = n / l;
            string matching = "";

            while (times--)
                matching += str;

            if (matching == s)
                return true;
        }
    }
    return false;
}

int main()
{
    cout << repeatedSubstringPattern("abcabcabcabc") << endl;
    return 0;
}