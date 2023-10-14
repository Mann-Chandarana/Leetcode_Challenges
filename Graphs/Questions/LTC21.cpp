/*--------  Hard --------*/

/*- Shortest Path Visiting All Nodes -*/

//////// Question number 847.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#define pii pair<int, int>

int shortestPathLength(vector<vector<int>> &graph)
{
    int n = graph.size();

    if (n == 1 || n == 0)
        return 0;

    queue<pii> q;
    set<pii> visited;

    for (int i = 0; i < n; i++)
    {
        int maskValue = 1 << i;
        q.push({i, maskValue});

        visited.insert({i, maskValue});
    }

    int allVisited = (1 << n) - 1;

    int path = 0;

    while (!q.empty())
    {
        int size = q.size();
        path++;

        while (size--)
        {
            int curr = q.front().first;
            int currmask = q.front().second;
            q.pop();

            for (auto neigh : graph[curr])
            {
                int nextmask = currmask | (1 << neigh);

                if (nextmask == allVisited)
                    return path;

                if (visited.find({neigh, nextmask}) == visited.end())
                {
                    visited.insert({neigh, nextmask});
                    q.push({neigh, nextmask});
                }
            }
        }
    }
    return -1;
}

int main()
{
    return 0;
}