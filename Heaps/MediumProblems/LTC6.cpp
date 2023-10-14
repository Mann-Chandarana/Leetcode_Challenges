/*--------Medium-----------*/

/*- Task Scheduler -*/

//////// Question number 621.

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int max(int a, int b)
{
    return a >= b ? a : b;
}

ll leastInterval(vector<char> &tasks, ll n)
{
    vector<ll> frequeny(26, 0);

    for (ll i = 0; i < tasks.size(); i++)
        frequeny[tasks[i] - 'A']++;

    ll maxi = *max_element(frequeny.begin(), frequeny.end());

    ll answer = ((maxi - 1) * (n + 1));

    for (ll i = 0; i < 26; i++)
    {
        if (frequeny[i] == maxi)
            answer++;
    }

    return max(answer, tasks.size());
}

int main()
{
    return 0;
}