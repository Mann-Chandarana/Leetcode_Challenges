#include <bits/stdc++.h>
using namespace std;

void printGfg(int N)
{
    if (N == 0)
    {
        return;
    }
    cout << "GFG"
         << " ";
    printGfg(N - 1);
}

int main()
{
    return 0;
}