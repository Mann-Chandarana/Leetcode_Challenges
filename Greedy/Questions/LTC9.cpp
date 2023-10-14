/*--------  Medium --------*/

/*- Remove Colored Pieces if Both Neighbors are the Same Color -*/

//////// Question number 2038.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

bool winnerOfGame(string colors)
{
    int n = colors.size();

    int alice = 0;

    for (int i = 1; i < n - 1; i++)
    {
        if (colors[i - 1] == colors[i] and colors[i] == colors[i + 1])
        {
            if (colors[i] == 'A')
                alice++;
            else
                alice--;
        }
    }

    return alice > 0;
}

int main()
{
    cout << winnerOfGame("AAAABBBB") << endl;

    return 0;
}