/*-------- Medium --------*/

/*- Find Closest Node to Given Two Nodes -*/

//////// Question number 2359.

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &distance, vector<int> edges, int dist)
{
    while (node != -1 && distance[node] == -1)
    {
        distance[node] = dist++;
        node = edges[node];
    }
}

int closestMeetingNode(vector<int> &edges, int node1, int node2)
{
    int n = edges.size();
    vector<int> dist1(n, -1), dist2(n, -1);

    dfs(node1, dist1, edges, 0);
    dfs(node2, dist2, edges, 0);

    int min_dis = INT_MAX, res = -1;

    for (int i = 0; i < n; i++)
    {
        if (min(dist1[i], dist2[i]) >= 0 and max(dist1[i], dist2[i]) <min_dis)
        {
            min_dis = max(dist1[i], dist2[i]);
            res = i;
        }
    }
    return res;
}

int main()
{
    return 0;
}