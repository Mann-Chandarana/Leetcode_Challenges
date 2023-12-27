/*-------- Medium --------*/

/*- Minimum Time to Make Rope Colorful -*/

//////// Question number 1578.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int minCost(string colors, vector<int> &neededTime)
{
    int n = neededTime.size();

    int time = 0, previous = 0;

    for (int i = 1; i < n; i++)
    {
        if (colors[previous] == colors[i])
        {
            if (neededTime[previous] < neededTime[i])
            {
                time += neededTime[previous];
                previous = i;
            }
            else
                time += neededTime[i];
        }
        else
            previous = i;
    }
    return time;
}

int main()
{
    return 0;
}