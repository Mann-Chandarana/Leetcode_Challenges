/*--------  Medium --------*/

/*- Minimum Cost to Make All Characters Equal -*/

//////// Question number 2712.

#include <bits/stdc++.h>
using namespace std;

long long minimumCost(string s)
{
    long long ans = 0;
    int n = s.size();
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
            ans += min(i, n - i);
    }
    return ans;
}

int main()
{
    return 0;
}