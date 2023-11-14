/*--------  Medium --------*/

/*- Sort Vowels in a String -*/

//////// Question number 2785.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/* Approach -1) */

bool isVowel(char ch)
{
    if ((ch == 'a' || ch == 'A') or (ch == 'e' || ch == 'E') or (ch == 'i' || ch == 'I') or (ch == 'o' || ch == 'O') or (ch == 'u' || ch == 'U'))
        return true;

    return false;
}

string sortVowels(string s)
{
    int n = s.length();

    string ans;

    for (int i = 0; i < n; i++)
    {
        if (isVowel(s[i]))
            ans.push_back(s[i]);
    }
    sort(all(ans));

    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (isVowel(s[i]))
            s[i] = ans[j++];
    }
    return s;
}

/* Approach -2) */

bool isVowel(char ch)
{
    ch = tolower(ch);
    if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u')
        return true;

    return false;
}

string sortVowels(string s)
{
    int n = s.length();

    unordered_map<char, int> mp;

    for (int i = 0; i < n; i++)
    {
        if (isVowel(s[i]))
            mp[s[i]]++;
    }

    string temp = "AEIOUaeiou";

    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (isVowel(s[i]))
        {
            while (mp[temp[j]] == 0)
                j++;

            s[i] = temp[j];
            mp[temp[j]]--;
        }
    }
    return s;
}

int main()
{
    cout << sortVowels("lEetcOde") << endl;
    return 0;
}