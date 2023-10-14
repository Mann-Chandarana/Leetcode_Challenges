/* Geeks for Geeks :- Basics of Bit manipulation */

#include <bits/stdc++.h>
using namespace std;

void bitManipulation(int num, int i)
{
    // Get ith bit

    int mask = 1 << (i-1);
    if((num & mask))
      cout<<1<<" ";
    else 
      cout<<0<<" ";

    // set ith bit

    mask = 1 << (i-1);
    int value = num | mask;

    cout << value << " ";

    // clear ith bit;

    mask = 1 << (i-1);
    mask = ~mask;
    num = num & mask;
    cout << num;
}

int main()
{
    bitManipulation(70, 3);
    return 0;
}