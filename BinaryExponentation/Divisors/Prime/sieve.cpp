#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

const int N = 1e7 + 10;

/* O(N(log(logN))) */

vector<bool> Sieve(int n)
{
    vector<bool> isPrime(n, 1);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = 2; j < 2 * i; j += i)
                isPrime[j] = false;
        }
    }

    return isPrime;
}

/* Prime Factors using Sieve */

vector<bool> Prime_factors(int n)
{
    vector<bool> isPrime(n, 1);
    vector<int> hp(n, 0), lp(n, 0);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            lp[i] = hp[i] = i;
            for (int j = 2 * i; j < n; j += i)
            {
                isPrime[j] = false;
                hp[j] = i;
                if (lp[j] == 0)
                    lp[j] = i;
            }
        }
    }

    int num;
    cin >> num;

    map<int, int> P_Factor;

    while (num > 1)
    {
        int primefactor = hp[num];

        while (num % primefactor == 0)
        {
            num /= primefactor;
            P_Factor[primefactor]++;
        }
    }

    return isPrime;
}

int main()
{
    return 0;
}