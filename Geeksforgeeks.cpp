#include <bits/stdc++.h>
using namespace std;

int finalDestination(int N, int M, int K, vector<vector<int>> &Roads)
{
    vector<pair<int, int>> adj[N];

    for (int i = 0; i < M; i++)
    {
        int source = Roads[i][0];
        int destination = Roads[i][1];
        int cost = Roads[i][2];

        adj[source].push_back({destination, cost});
    }

    vector<int> dist(N, 1e9);
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int source = pq.top().second;
        pq.pop();

        for (auto element : adj[source])
        {
            if (K > 0 and element.second % 2 != 0 and (element.second) / 2 + cost < dist[element.first])
            {
                dist[element.first] = (element.second / 2) + cost;
                pq.push({dist[element.first], element.first});
                K--;
            }
            else if (element.second + cost < dist[element.first])
            {
                dist[element.first] = (element.second + cost);
                pq.push({dist[element.first], element.first});
            }
        }
    }

    return dist[N - 1] == 1e9 ? -1 : dist[N - 1];
}

int main()
{
    vector<vector<int>> Roads = {{0, 1, 7}, {2, 1, 92}, {3, 2, 5}, {2, 3, 1}};
    cout << finalDestination(4, 4, 2, Roads) << endl;
    return 0;
}