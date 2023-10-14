/*--------Medium-----------*/

/*- Most Stones Removed with Same Row or Column -*/

//////// Question number 947.

#include <bits/stdc++.h>
using namespace std;

/* Using DFS */

bool valid(vector<int> &p1, vector<int> &p2)
{
    if (p1[0] == p2[0])
        return true;
    if (p1[1] == p2[1])
        return true;
    return false;
}
void dfs(vector<vector<int>> &stones, vector<bool> &visited, int i)
{
    visited[i] = true;
    for (int j = 0; j < stones.size(); j++)
    {
        if (valid(stones[i], stones[j]) && !visited[j])
        {
            dfs(stones, visited, j);
        }
    }
}
int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(stones, visited, i);
            count++;
        }
    }

    return n - count;
}

/* Using BFS */

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
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

int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    int maxRow = 0;
    int maxCol = 0;
    for (auto it : stones)
    {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }
    DisjointSet ds(maxRow + maxCol + 1);
    unordered_map<int, int> stoneNodes;
    for (auto it : stones)
    {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        ds.unionBySize(nodeRow, nodeCol);
        stoneNodes[nodeRow] = 1;
        stoneNodes[nodeCol] = 1;
    }

    int cnt = 0;
    for (auto it : stoneNodes)
    {
        if (ds.findUPar(it.first) == it.first)
        {
            cnt++;
        }
    }
    return n - cnt;
}

int main()
{

    return 0;
}
