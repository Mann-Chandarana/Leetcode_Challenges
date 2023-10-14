/*1704. Determine if String Halves Are Alike*/

#include <bits/stdc++.h>
using namespace std;

int countVowel(string s, int start, int end)
{
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        char ch = s[i];
        if (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or
            ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U')
        {
            count++;
        }
    }
    return count;
}

bool halvesAreAlike(string s)
{
    int len = s.length() / 2;
    int count1 = countVowel(s, 0, len - 1);
    int count2 = countVowel(s, len, s.length());

    return (count1 == count2);
}

int main()
{
    cout << halvesAreAlike("textbook") << endl;
    return 0;
}