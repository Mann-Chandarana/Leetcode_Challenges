#include <bits/stdc++.h>
using namespace std;

bool isPossibleToColor(int node, bool graph[101][101], vector<int> &colors, int color, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i != node and graph[node][i] and colors[i] == color)
            return false;
    }
    return true;
}

bool solve(int node, bool graph[101][101], int m, int n, vector<int> &colors)
{
    if (node == n)
    {
        return true; // i colored every node
    }
    for (int i = 1; i <= m; i++)
    {
        if (isPossibleToColor(node, graph, colors, i, n))
        {
            colors[node] = i;

            if (solve(node + 1, graph, m, n, colors))
                return true;

            colors[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> colors(n);
    return solve(0, graph, m, n, colors);
}

int main()
{
    bool graph[101][101] = {(0, 1), (1, 2), (0, 2)};
    cout << graphColoring(graph, 4, 3);

    return 0;
}