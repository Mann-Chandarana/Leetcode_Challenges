/*--------Medium-----------*/

/*- Maximum Subsequence Score -*/

//////// Question number 2542.

#include <bits/stdc++.h>
using namespace std;

long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n = nums1.size();
    vector<pair<int, int>> vec(n);

    for (int i = 0; i < n; i++)
        vec.push_back({nums1[i], nums2[i]});

    auto lambda = [&](auto &P1, auto &P2)
    {
        return P1.second > P2.second;
    };

    sort(vec.begin(), vec.end(), lambda);

    priority_queue<int, vector<int>, greater<int>> pq; // minHeap

    long long ksum = 0;

    for (int i = 0; i <= k - 1; i++)
    {
        ksum += vec[i].first;
        pq.push(vec[i].first);
    }

    long long result = ksum * vec[k - 1].second;

    for (int i = k; i < n; i++)
    {
        ksum += vec[i].first - pq.top();
        pq.pop();

        pq.push(vec[i].first);
        result = max(result, ksum * vec[i].second);
    }
    return result;
}

int main()
{
    return 0;
}