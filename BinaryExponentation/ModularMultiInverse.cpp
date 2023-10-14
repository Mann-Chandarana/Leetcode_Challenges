#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int binExpIter(int a, int b)
{
    int ans = 1;

    while (b)
    {
        if (b & 1)
            ans = (ans * 1LL * a) % MOD;
        a = (a * 1LL * a) % MOD;
        b >>= 1;
    }
    return ans;
}

/* There are N children and K toffees ,K<N count the number of ways to distribute toffee among N students such that each students get 1 toffee only --> nCk % M,M=10^9+7
N<10^6 , K < N < 10^6
Q < 10^5
(!n/(n-r)!*r!)
*/

const int N = 1e6 + 10;
int fact[N];

int main()
{
    // int a;
    // // To find inverse of the number
    // binExpIter(a, MOD - 2);

    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i-1]*1LL*i)%MOD;
    }
    int q;
    cin>>q;
 
    while (q--)
    {
        int n,k;
        cin>>n>>k;
        int ans = fact[n];
        int den = (fact[n-r]*1LL*fact[r])%MOD;
        ans = ans*binExpIter(den,M-2,MOD);
    }
    
    

    return 0;
}