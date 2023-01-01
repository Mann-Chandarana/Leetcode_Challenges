// Print 1 To N Without Loop :- geeks for geekss

#include <bits/stdc++.h>
using namespace std;

void printNos(int N)
{
    if (N == 0)
        return;

    printNos(N - 1);
    cout << N << " ";
}

int main()
{
    return 0;
}