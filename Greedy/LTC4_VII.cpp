/*-------- Medium -----------*/

/*- Gas Station -*/

//////// Question number 134.

#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size(), start = 0, total = 0, diff;
    vector<int> diff(n);

    for (int i = 0; i < n; i++)
    {
        diff += gas[i] - cost[i];
        if (diff < 0)
        {
            start = i + 1;
            total += diff;
            diff = 0;
        }
    }

    return total + diff < 0 ? -1 : start;
}

int main()
{
    return 0;
}