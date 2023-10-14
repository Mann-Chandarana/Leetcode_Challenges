/*--------Medium-----------*/

/*- Is Graph Bipartite? -*/

//////// Question number 785.

#include <bits/stdc++.h>
using namespace std;

/* Using BFS */

bool bfs(int node, int color, vector<vector<int>> &graph, vector<int> &colors)
{
    colors[node] = color;
    queue<pair<int, int>> q;

    q.push({node, color});

    while (!q.empty())
    {
        int node1 = q.front().first;
        int currentcolor = q.front().second;
        q.pop();

        for (auto child : graph[node1])
        {
            if (colors[child] == -1)
                q.push({child, !currentcolor});

            else if (colors[child] == currentcolor)
                return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!bfs(i, 0, graph, color))
                return false;
        }
    }
    return true;
}

/* Using DFS */

bool dfs(int node, int color, vector<vector<int>> &graph, vector<int> &colors)
{
    colors[node] = color;

    for (auto child : graph[node])
    {
        if (colors[child] == -1)
        {
            if (!dfs(child, !color, graph, colors))
                return false;
        }
        else if (colors[child] == color)
            return false;
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (dfs(i, 0, graph, color))
                return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}