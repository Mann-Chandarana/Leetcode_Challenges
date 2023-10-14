/* Geeks for Geeks :- Prim's Algorithm */

#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int sum = 0;

    vector<bool> visited(V, false);

    pq.push({0, 0});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int edgeWt = pq.top().first;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        sum += edgeWt;

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int weight = it[1];

            if (!visited[adjNode])
                pq.push({weight, adjNode});
        }
    }

    return sum;
}

int main()
{
    return 0;
}