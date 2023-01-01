/*--------Medium-----------*/

/*- Remove Stones to Minimize the Total -*/

//////// Question number 1962.

#include <bits/stdc++.h>
using namespace std;

int minStoneSum(vector<int> &piles, int k)
{
    priority_queue<int> pq(piles.begin(), piles.end());

    while (k--)
    {
        int tp = pq.top();
        pq.pop();
        tp -= ((tp) / 2);
        pq.push(tp);
    }

    int ans = 0;

    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }

    return ans;
}

int main()
{
    vector<int> piles = {5, 4, 9};
    cout << minStoneSum(piles, 2) << endl;
    return 0;
}