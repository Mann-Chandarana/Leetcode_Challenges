/*--------  Medium --------*/

/*- Check if Strings Can be Made Equal With Operations II -*/

//////// Question number 2840.

#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

/******* Using Maps ********/

bool checkStrings(string s1, string s2)
{
    int n = s1.length(), m = s2.length();

    if (n != m)
        return false;

    unordered_map<char, int> even1, even2, odd1, odd2;

    for (int i = 0; i < n; i++)
    {
        if (!(i & 1))
            even1[s1[i]]++, even2[s2[i]]++;

        else
            odd1[s1[i]]++, odd2[s2[i]]++;
    }

    return (even1 != even2 || odd1 != odd2) ? false : true;
}

/******* Without Using Maps ********/

bool checkStrings(string s1, string s2)
{
    int n = s1.length(), m = s2.length();

    if (n != m)
        return false;

    string even1 = "", even2 = "", odd1 = "", odd2 = "";

    for (int i = 0; i < n; i++)
    {
        if (!(i & 1))
            even1 += s1[i], even2 += s2[i];

        else
            odd1 += s1[i], odd2 += s2[i];
    }
    sort(all(even1));
    sort(all(even2));
    sort(all(odd1));
    sort(all(odd2));

    return (even1 != even2 || odd1 != odd2) ? false : true;
}

int main()
{
    return 0;
}