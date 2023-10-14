/* Geeks for Geeks :- Swap two numbers */

#include <bits/stdc++.h>
using namespace std;

pair<int, int> get(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    return {a, b};
}

int main()
{
    return 0;
}