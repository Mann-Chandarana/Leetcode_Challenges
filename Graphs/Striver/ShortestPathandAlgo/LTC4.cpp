/*--------Medium-----------*/

/*- Network Delay Time -*/

//////// Question number 743.

#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<pair<int, int>> adj[n + 1];

    for (auto element : times)
        adj[element[0]].push_back({element[1], element[2]});

    vector<int> distance(n + 1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[k] = 0;
    distance[0] = 0;
    pq.push({0, k});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto child : adj[node])
        {
            if (dis + child.second < distance[child.first])
            {
                distance[child.first] = dis + child.second;
                pq.push({distance[child.first], child.first});
            }
        }
    }

    if (*max_element(distance.begin(), distance.end()) != 1e9)
        return *max_element(distance.begin(), distance.end());
    else
        return -1;
}

int main()
{
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << networkDelayTime(times, 4, 2) << endl;
    return 0;
}