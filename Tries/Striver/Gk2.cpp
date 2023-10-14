/* Geeks for geeks :- Bit PreRequisites for TRIE Problems */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int XOR(int n, int m)
    {
        return n ^ m;
    }
    int check(int a, int b)
    {
        return (b >> (a - 1)) & 1;
    }
    int setBit(int c, int d)
    {
        d = d | (1 << c);
        return d;
    }
};

int main()
{
    return 0;
}