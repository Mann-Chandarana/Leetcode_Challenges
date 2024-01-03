/*-------- Medium --------*/

/*- Number of Laser Beams in a Bank -*/

//////// Question number 2125.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int numberOfBeams(vector<string> &bank)
{
    int n = bank.size();

    int prev = 0, answer = 0;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < bank[i].size(); j++)
        {
            if (bank[i][j] == '1')
                count++;
        }

        if (count != 0)
        {
            answer += (count * prev);
            prev = count;
        }
    }
    return answer;
}

int main()
{
    return 0;
}