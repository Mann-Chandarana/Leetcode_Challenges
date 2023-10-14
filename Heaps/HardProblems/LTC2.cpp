/* Minimum Cost of ropes */

/* https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-cost-of-ropes */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll minCost(ll arr[], ll n)
{
    priority_queue<ll, vector<ll>, greater<ll>> pq; // Minheap

    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    ll total_sum = 0;

    while (pq.size() != 1)
    {
        ll cost1 = pq.top();
        pq.pop();
        ll cost2 = pq.top();
        pq.pop();

        total_sum += cost1 + cost2;
        pq.push(cost1 + cost2);
    }
    return total_sum;
}

int main()
{
    ll arr[] = {4, 2, 7, 6, 9};
    cout << minCost(arr, 5) << endl;
    return 0;
}