// 242. Valid Anagram

#include <bits/stdc++.h>
using namespace std;

/* We can also use hashing in this question */

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i])
            return false;
    }
    return true;
}

int main()
{
    return 0;
}