// Print N To 1 Without Loop :- geeks for geekss

#include <bits/stdc++.h>
using namespace std;

void printNos(int N)
{
    if (N == 0)
        return;

    cout << N << " ";
    printNos(N - 1);
}

int main()
{
    return 0;
}