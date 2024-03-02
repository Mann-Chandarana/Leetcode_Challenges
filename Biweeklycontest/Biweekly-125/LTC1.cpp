#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int minOperations(vector<int> &nums, int k)
{
    ll operations = 0;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (auto &element : nums)
        pq.push(element);

    while (!pq.empty() and pq.top() < k)
    {
        ll num1 = pq.top();
        pq.pop();

        ll num2 = pq.top();
        pq.pop();

        operations++;

        ll final_result = (min(num1, num2) * (1ll) * 2) + max(num1, num2);

        pq.push(final_result);
    }

    return operations;
}

int main()
{
    return 0;
}