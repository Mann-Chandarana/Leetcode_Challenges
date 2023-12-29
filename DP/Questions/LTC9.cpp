/*-------- Hard --------*/

/*- String Compression II -*/

//////// Question number 1531.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int solve(string s, int i, int prev, int freq, int k)
{
    if (k < 0)
        return INT_MAX;

    if (i >= s.length())
        return 0;

    int delete_i = solve(s, i + 1, prev, freq, k - 1);

    int keep_i = 0;

    if (s[i] - 'a' == prev)
    {
        int one_more_add = 0;
        if (freq == 1 || freq == 9 || freq == 99)
            one_more_add++;
        
        keep_i = one_more_add+solve(s,i+1,prev,freq+1,k);
    }
    else
       keep_i = 1 + solve(s,i+1,s[i]-'a',1,k);

    return min(delete_i,keep_i);
}

int getLengthOfOptimalCompression(string s, int k)
{
    int n = s.length();

    return solve(s,0,26,0,k);
}

int main()
{
    cout << getLengthOfOptimalCompression("", 0) << endl;

    return 0;
}