/* Geeks for Geeks :- Set and unset the rightmost unset bit */

#include <bits/stdc++.h>
using namespace std;

int setBit(int n)
{
    return (n & (n + 1)) ? (n | (n + 1)) : n;
}

int main()
{
    return 0;
}