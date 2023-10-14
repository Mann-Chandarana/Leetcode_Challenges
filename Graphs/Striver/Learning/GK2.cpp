/* Geeks for Geeks :- Print adjacency list */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printGraph(int V, vector<int> adj[])
{
    vector<vector<int>> adjaceny(V);

    for (int i = 0; i < V; i++)
    {
        adjaceny[i].push_back(i);
        for (auto element : adj[i])
            adjaceny[i].push_back(element);
    }

    return adjaceny;
}

int main()
{
    return 0;
}