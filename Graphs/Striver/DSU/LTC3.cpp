/*-------- Hard -----------*/

/*- Making A Large Island -*/

//////// Question number 827.


#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

public:
    vector<int> rank, parent, size;
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

bool isValid(int newr, int newc, int n)
{
    return newr >= 0 && newr < n && newc >= 0 && newc < n;
}

int largestIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    DisjointSet ds(n * n);

    // step-1

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 0)
                continue;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dr[i], ncol = col + dc[i];
                if (isValid(nrow, ncol, n) and grid[nrow][ncol] == 1)
                {
                    int nodeNo = row * n + col;
                    int adjNo = nrow * n + ncol;
                    ds.unionBySize(nodeNo, adjNo);
                }
            }
        }
    }

    // step-2

    int mx = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (grid[row][col] == 1)
                continue;

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            set<int> component;
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dr[i], ncol = col + dc[i];
                if (isValid(nrow, ncol, n) and grid[nrow][ncol] == 1)
                {
                    int nodeNo = row * n + col, adjNo = nrow * n + ncol;
                    component.insert(ds.findUPar(adjNo));
                }
            }
            int size_total = 0;

            for (auto element : component)
                size_total += ds.size[element];

            mx = max(mx, size_total+1);
        }
    }
    for (int cellNo = 0; cellNo < n * n; cellNo++)
    {
        mx = max(mx, ds.size[ds.findUPar(cellNo)]);
    }
    return mx;
}

int main()
{
    return 0;
}