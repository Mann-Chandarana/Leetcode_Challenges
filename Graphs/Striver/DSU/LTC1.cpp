/*--------Medium-----------*/

/*- Number of Operations to Make Network Connected -*/

//////// Question number 1319.

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int makeConnected(int n, vector<vector<int>> &connections)
{
    DisjointSet ds(n);
    vector<bool> visited(n, false);

    int cnt = 0;

    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];

        visited[u] = true;
        visited[v] = true;

        if (ds.findUPar(u) != ds.findUPar(v))
            ds.unionBySize(u, v);
        else
            cnt++;
    }
    int cnt1 = cnt;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            cnt--;
    }
    return cnt == 0 ? cnt1 : -1;
}

int main()
{
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2}};
    cout << makeConnected(6, connections) << endl;
    return 0;
}