/*--------  Medium --------*/

/*- Count K-Subsequences of a String With Maximum Beauty -*/

//////// Question number 2842.

#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

long long power(int x, int n)
{
    if (n == 0)
        return 1;

    long long ans = power(x, n / 2);

    if (n & 1)
        return (x * 1LL * ((ans * 1LL * ans) % MOD)) % MOD;
    else
        return (ans * 1LL * ans) % MOD;

    return ans;
}

long long fact(int n)
{
    long long ans = 1;

    for (int i = 1; i <= n; i++)
        ans *= i, ans %= MOD;

    return ans;
}

long long nCr(int n, int r)
{
    long long ans = fact(n);
    long long denominator = ((fact(r) % MOD) * (fact(n - r) % MOD)) % MOD;

    return ans * power(denominator, MOD - 2); // find inverse of a nubmer ans then multiplying with the answer
}

int countKSubsequencesWithMaxBeauty(string s, int k)
{
    priority_queue<int> pq;

    vector<int> freq(26);

    for (auto x : s)
        freq[x - 'a'] += 1;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
            pq.push(freq[i]);
    }

    if (pq.size() < k)
        return 0;

    long long ans = 1;
    while (k > 0)
    {
        int countEqualfreq = 0, freq = pq.top();

        while (pq.size() > 0 and pq.top() == freq)
        {
            countEqualfreq += 1;
            pq.pop();
        }

        if (countEqualfreq <= k)
        {
            k -= countEqualfreq;
            ans *= power(freq, countEqualfreq);
            ans %= MOD;
        }
        else
        {
            ans *= power(freq, k);
            ans %= MOD;

            ans *= (nCr(countEqualfreq, k) % MOD);
            ans %= MOD;
            break;
        }
    }
    return ans;
}

int main()
{
    return 0;
}