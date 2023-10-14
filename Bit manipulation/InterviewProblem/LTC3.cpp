/*--------  Medium --------*/

/*- Minimum Flips to Make a OR b Equal to c -*/

//////// Question number 1318.

#include <bits/stdc++.h>
using namespace std;

int minFlips(int a, int b, int c)
{
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        if (c & 1)
        {
            if (!(a & 1) and !(b & 1))
                count++;
        }
        else
        {
            if (a & 1)
                count++;

            if (b & 1)
                count++;
            
        }
        a >>= 1, b >>= 1, c >>= 1;
    }

    return count;
}

int main()
{
    cout << minFlips(8, 3, 5) << endl;
    return 0;
}