/*-------- Medium -----------*/

/*- Maximum Ice Cream Bars -*/

//////// Question number 1833.

#include <bits/stdc++.h>
using namespace std;

int maxIceCream(vector<int> &costs, int coins)
{
    sort(costs.begin(), costs.end());
    int no = 0;

    for (int i = 0; i < costs.size(); i++)
    {
        if (coins >= costs[i])
        {
            coins -= costs[i];
            no++;
        }
        else
        {
            return no;
        }
    }

    return no;
}

int main()
{

    return 0;
}