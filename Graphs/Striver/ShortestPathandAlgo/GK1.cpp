/* Geeks for Geeks :- Shortest Path in Weighted undirected graph */

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    unordered_map<int, vector<pair<int, int>>> mp;

    for (auto element : edges)
    {
        mp[element[0]].push_back({element[1], element[2]});
        mp[element[1]].push_back({element[0], element[2]});
    }

    vector<int> distance(n + 1, 1e9);
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto child : mp[node])
        {
            if (dis + child.second < distance[child.first])
            {
                parent[child.first] = node;
                distance[child.first] = dis + child.second;
                pq.push({distance[child.first], child.first});
            }
        }
    }

    if (distance[n] == 1e9)
        return {-1};
    int i = n;

    vector<int> answer;
    answer.push_back(n);

    while (parent[i] != i)
    {
        answer.push_back(parent[i]);
        i = parent[i];
    }
    reverse(answer.begin(), answer.end());

    return answer;
}

int main()
{
    return 0;
}