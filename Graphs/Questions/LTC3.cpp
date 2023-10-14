/*-------- Medium -----------*/

/*- Possible Bipartition -*/

//////// Question number 886.

#include <bits/stdc++.h>
using namespace std;

/************** Using BFS *****************/

bool bfs(unordered_map<int, vector<int>> neighbour, vector<int> &groups, int src)
{
    queue<int> q;
    q.push(src);
    groups[src] = 1;

    while (!q.empty())
    {
        int element = q.front();
        q.pop();

        for (auto neigh : neighbour[element])
        {
            if (groups[neigh] == groups[element])
            {
                return false;
            }
            if (groups[neigh] == -1)
            {
                q.push(neigh);
                groups[neigh] = abs(1 - groups[element]);
            }
        }
    }
    for (auto element : groups)
    {
        cout << element << " ";
    }
    cout << endl;
    return true;
}

bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{
    unordered_map<int, vector<int>> neighbour;

    for (int i = 0; i < dislikes.size(); i++)
    {
        neighbour[dislikes[i][0]].push_back(dislikes[i][1]);
        neighbour[dislikes[i][1]].push_back(dislikes[i][0]);
    }

    for (auto element : neighbour)
    {
        cout << element.first << " --> ";
        for (auto j : element.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    vector<int> groups(n + 1, -1);
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (groups[i] == -1)
        {
            if (!bfs(neighbour, groups, i))
            {
                return false;
            }
        }
    }

    return true;
}

/************** Using DFS *****************/

bool isBipartite(int node, int color, vector<int> &isVisited, vector<int> adj[])
{
    isVisited[node] = color;
    int adjColor = (color == 1) ? 2 : 1;
    for (auto i : adj[node])
    {
        if (!isVisited[i])
        {
            if (isBipartite(i, adjColor, isVisited, adj))
            {
                return true;
            }
        }
        else if (isVisited[i] == color)
        {
            return true;
        }
    }
    return false;
}
bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{
    vector<int> adj[n + 1];
    for (auto i : dislikes)
    {
        int u = i[0];
        int v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> isVisited(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            if (isBipartite(i, 1, isVisited, adj))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> dislikes = {{1, 2}, {3, 4}, {4, 5}, {3, 5}};
    cout << possibleBipartition(5, dislikes) << endl;
    return 0;
}