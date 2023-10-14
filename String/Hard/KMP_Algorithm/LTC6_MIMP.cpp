/*-------- Hard -----------*/

/*- Shortest Palindrome -*/

//////// Question number 214.


#include <bits/stdc++.h>
using namespace std;

int lps(string s)
{
    int n = s.length();
    vector<int> LPS(n, 0);
    LPS[0] = 0;

    int i = 1, len = 0;

    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
                LPS[i] = 0, i++;

            else
                len = LPS[len - 1];
        }
    }
    return LPS[n - 1];
}

string shortestPalindrome(string s)
{
    string reverse_str = s;
    reverse(reverse_str.begin(), reverse_str.end());

    string new_str = s + "#" + reverse_str;

    int longest_palindromic_sequence = lps(new_str);

    return reverse_str.substr(0, s.size() - longest_palindromic_sequence) + s;
}

int main()
{
    return 0;
}