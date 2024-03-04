/*-------- Medium --------*/

/*- Bag of Tokens -*/

//////// Question number 948.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int bagOfTokensScore(vector<int> &tokens, int power)
{
    int n = tokens.size();

    sort(all(tokens));

    if (tokens.size() == 0 || tokens[0] > power)
        return 0;

    int i = 0, j = n - 1, score = 0;

    while (i <= j)
    {
        if (i == j)
        {
            if (power >= tokens[i])
                power -= tokens[i++], score++;
            else
                power += tokens[j--], score--;
        }

        else if (power >= tokens[i])
            power -= tokens[i++], score++;
        else
            power += tokens[j--], score++;
    }
    return score;
}

int main()
{
    return 0;
}