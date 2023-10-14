/* 520. Detect Capital */

#include <bits/stdc++.h>
using namespace std;

bool detectCapitalUse(string word)
{
    int capi = 0,  n = word.length();

    for (int i = 0; i < n; i++)
    {
        if (isupper(word[i]))
        {
            capi++;
        }
    }

    if ((capi == n) || (capi == 0) || (capi == 1 and isupper(word[0])))
        return true;

    return false;
}

int main()
{
    cout<<detectCapitalUse("Google")<<endl;
    return 0;
}