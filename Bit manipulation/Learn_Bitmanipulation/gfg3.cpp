/* Geeks for Geeks :- Check whether Kth bit is set or not */

#include <bits/stdc++.h>
using namespace std;

bool checkKthBit(int n, int k)
{
    int mask = 1 << (k);
    if (n & mask)
        return true;
    else
        return false;
}

int main()
{
    return 0;
}