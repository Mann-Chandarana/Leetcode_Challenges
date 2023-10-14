/*--------Medium-----------*/

/*- Stone game -*/

//////// Question number 877.

#include <bits/stdc++.h>
using namespace std;

bool stoneGame(vector<int> &piles)
{
    int i = 0, j = piles.size() - 1, a = 0, b = 0;

    while (i < j)
    {
        if (piles[i] > piles[j])
        {
            a += piles[i++];
            b += piles[j--];
        }
        else
        {
            a += piles[j--];
            b += piles[i++];
        }
    }
    return a>b;
}

int main()
{
    return 0;
}