/* Geeks for Geeks :- Count Number of substrings */

#include <bits/stdc++.h>
using namespace std;

long long int solve(string &str, int n, int k)
{
    // intially windows size
    int i = 0, j = 0;
    long long int ans = 0;
    long long int dist = 0;

    int hash_cnt[26] = {0};

    while (j < n)
    {
        hash_cnt[str[j] - 'a']++;
        if (hash_cnt[str[j] - 'a'] == 1)
            dist++;

        // decrease the size of window
        while (dist > k)
        {
            hash_cnt[str[i] - 'a']--;
            if (hash_cnt[str[i] - 'a'] == 0)
                dist--;

            i++;
        }

        ans += j - i + 1;
        j++;
    }
    return ans;
}
long long int substrCount(string str, int k)
{
    int n = str.size();
    return solve(str, n, k) - solve(str, n, k - 1);
}

int main()
{
    return 0;
}