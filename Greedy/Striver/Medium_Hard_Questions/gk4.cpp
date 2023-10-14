/* Geeks for Geeks :- Shortest Job first */

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &bt)
{
    sort(bt.begin(), bt.end());
    int sum = 0, diff = 0;
    for (int i = 0; i < bt.size(); i++)
    {
        sum += bt[i];
        diff = sum - bt[i];
    }
    return diff/(bt.size());
}

int main()
{
    return 0;
}