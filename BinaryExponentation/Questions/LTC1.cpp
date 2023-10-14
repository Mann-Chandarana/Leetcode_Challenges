/*-------- Medium -----------*/

/*- Super Pow -*/

//////// Question number 372.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define all(v) v.begin(), v.end()

/*
    Euler Totient Function
    
    O(n) :- O(1337) = 1337*(1-1/7)*(1-1/191)

    here 7 and 191 are the prime factors

    O(n) = 1140
*/

lli m = 1337;

lli get_num(vector<int> &b)
{
    if (b.size() == 0)
        return 0;

    if (b.size() == 1)
        return b[0];

    lli temp = 0;
    int cnt = 1;

    for (int i = b.size() - 1; i >= 0; i--)
    {
        temp += (cnt * b[i]) % 1140;
        cnt = (cnt * 10) % 1140;
    }
    return temp;
}

int binExpIter(lli a, lli b, lli m)
{
    if (b == 0)
        return 1;

    if (b == 1)
        return a;

    lli ans = 1;
    while (b)
    {
        if (1 & b)
            ans = (ans * a) % m;

        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

int superPow(int a, vector<int> &b)
{
    lli bbr = get_num(b);
    if (bbr == 0)
        return 0;

    if (bbr == 1)
        return a;

    return binExpIter(a, bbr, m);
}

int main()
{
    return 0;
}