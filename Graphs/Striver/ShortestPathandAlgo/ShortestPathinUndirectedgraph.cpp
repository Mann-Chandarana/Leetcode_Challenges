/* Geeks for Geeks :- Shortest path in Undirected Graph having unit distance */

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    vector<int> distance(N, 1e9);

    unordered_map<int, vector<int>> adj;

    for (auto element : edges)
    {
        adj[element[0]].push_back(element[1]);
        adj[element[1]].push_back(element[0]);
    }

    queue<pair<int, int>> q;

    q.push({src, 0});
    distance[src] = 0;

    while (!q.empty())
    {
        int node = q.front().first;
        q.pop();

        for (auto child : adj[node])
        {
            if (distance[node] + 1 < distance[child])
            {
                distance[child] = distance[node] + 1;
                q.push({child, distance[child]});
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (distance[i] == 1e9)
            distance[i] = -1;
    }
    return distance;
}

int main()
{
    return 0;
}