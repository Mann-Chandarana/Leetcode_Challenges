/* 2833. Furthest Point From Origin */

#include <bits/stdc++.h>
using namespace std;

int furthestDistanceFromOrigin(string moves)
{
    int under_L = 0, under_R = 0;

    for (int i = 0; i < moves.size(); i++)
    {
        if (moves[i] == 'L')
            under_L--, under_R--;

        else if (moves[i] == 'R')
            under_L++, under_R++;

        else
            under_L--, under_R++;
    }

    return max(abs(under_L), abs(under_R));
}

int furthestDistanceFromOrigin(string moves)
{
    int count1 = 0, count2 = 0, count3 = 0, n = moves.size();

    for (int i = 0; i < n; i++)
    {
        if (moves[i] == 'L')
            count1++;

        else if (moves[i] == 'R')
            count2++;

        else
            count3++;
    }

    return ((max(count1, count2) - min(count1, count2)) + count3);
}

int main()
{
    return 0;
}