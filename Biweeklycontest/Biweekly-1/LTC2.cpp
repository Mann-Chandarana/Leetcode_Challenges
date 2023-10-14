/*--------  Medium --------*/

/*- Count Total Number of Colored Cells -*/

//////// Question number 2579.

#include <bits/stdc++.h>
using namespace std;

long long coloredCells(int n)
{
    return long(n) * long(n) + long((n - 1)) * long((n - 1));
}

int main()
{
    cout << coloredCells(4) << endl;
    return 0;
}