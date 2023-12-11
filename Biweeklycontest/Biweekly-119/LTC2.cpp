/*--------  Medium --------*/

/*- Remove Adjacent Almost-Equal Characters -*/

//////// Question number 100152.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int removeAlmostEqualCharacters(string word)
{
    int n = word.size(), count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if ((word[i] == word[i + 1]) or (abs(word[i] - word[i + 1]) == 1))
            count++,i++;
    }
    return count;
}

int main()
{
    return 0;
}