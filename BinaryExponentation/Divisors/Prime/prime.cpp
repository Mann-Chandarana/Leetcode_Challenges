#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/* Number is prime or not */

bool isPrime(int n)
{
    bool is_prime = true;
    if (n == 1)
        return 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}

/* Prime factorization of a number */

vector<int> primeFactors(int n)
{
    vector<int> prime_factors;

    for (int i = 2; i * n <= n; i++)
    {
        while (n % i == 0)
        {
            prime_factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        prime_factors.push_back(n);

    return prime_factors;
}

int main()
{
    int n;
    cin >> n;

    cout << isPrime(n) << endl;

    return 0;
}