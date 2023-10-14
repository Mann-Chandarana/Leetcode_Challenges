/*** Optimised version of sieve of Eratosthenes ***/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* Naive approach */

bool isPrime(int n)
{
    if (n == 1)
        return false;

    if (n == 2)
        return true;

    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

/* Sieve of Erathosthenes */

void prime(ll *p)
{
    for (ll i = 2; i <= 1000000; i++)
        p[i] = 1;

    for (ll i = 2; i <= 1000000; i++)
    {
        if (p[i] == 1)
        {
            for (ll j = i * i; j <= 1000000; j += i)
            {
                if (p[j] == 1)
                    p[j] = 0;
            }
        }
    }
}

/* Optimised version */

void primeSieve(ll *p, ll n)
{

    p[0] = p[1] = 0;
    p[2] = 1;

    // Let us Mark all Odd Numbers as Prime(Initialisations)
    for (ll i = 3; i <= n; i += 2)
    {
        p[i] = 1;
    }

    // Sieve Login to mark non prime numbers as 0
    // 1. Optimsation : Iterate only over odd Numbers
    for (ll i = 3; i <= n; i += 2)
    {

        if (p[i])
        {
            // Mark all the multiples of that number as not prime.
            // 2. Optimisation Take a jump of 2i starting from i*i
            for (ll j = i * i; j <= n; j += i)
            {
                p[j] = 0;
            }
        }
    }
    int k = 0;
    for (int i = 2; i < 1000000; ++i)
    {
        if (p[i])
        {
            a[k] = i;
            k++;
        }
    }
    return;
}

int main()
{
    vector<ll> p(1000000, 0);
    return 0;
}