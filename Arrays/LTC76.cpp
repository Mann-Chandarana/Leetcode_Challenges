//////// Question number 345.

/*  Reverse a Vowels of a String  */

#include <bits/stdc++.h>
using namespace std;

bool is_matched(char a)
{
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
    {
        return true;
    }
    return false;
}

string reverseVowels(string s)
{
    int i = 0, j = s.length() - 1;
    bool matchA = false, matchB = false;

    while (i < j)
    {
        matchA = is_matched(s[i]);
        matchB = is_matched(s[j]);

        if (matchA && matchB)
        {
            swap(s[i++], s[j--]);
        }
        else if (matchA and !matchB)
        {
            j--;
        }
        else if (!matchA and matchB)
        {
            i++;
        }
        else
        {
            i++, j--;
        }
    }
    return s;
}

int main()
{
    cout << reverseVowels("aA") << endl;
    return 0;
}