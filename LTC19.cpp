/*-------- Medium --------*/

/*- Count Number of Homogenous Substrings -*/

//////// Question number 1759.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int mod = 1e9 + 7;
int countHomogenous(string s)
{
    ll n = s.length();

    ll answer = 0;

    ll count = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == s[i])
            count++;
        else
        {
            answer = ((answer + (((count * 1ll * (count + 1)) / 2)) % mod)) % mod;
            count = 1;
        }
    }
    answer = ((answer + (((count * 1ll * (count + 1)) / 2)) % mod)) % mod;
    return answer;
}

int main()
{
    return 0;
}