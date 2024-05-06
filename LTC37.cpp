#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

class DSU
{
public:
    int n;
    vector<int> parent, size;

    DSU(int n)
    {
        this->n = n;
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find_Parent(int node)
    {
        if (parent[node] == node)
            return n;

        return parent[node] = find_Parent(parent[node]);
    }

    void unionBySize(int a, int b)
    {
        int parent_a = find_Parent(a);
        int parent_b = find_Parent(b);

        if (parent_a == parent_b)
            return;

        if (size[parent_a] >= size[parent_b])
        {
            parent[parent_b] = parent_a;
            size[parent_a] += size[parent_b];
        }
        else
        {
            parent[parent_a] = parent_b;
            size[parent_b] += size[parent_a];
        }
    }
};

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool isValid(int adjr, int adjc, int n, int m)
{
    return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size(), m = grid[0].size();

    DSU ds(n * m);
    vector<vector<int>> visited(n, vector<int>(m, false));

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (grid[row][col] == '1')
            {
                for (int i = 0; i < 4; i++)
                {
                    int adjr = row + dr[i], adjc = col + dc[i];
                    if (isValid(adjr, adjc, n, m) and grid[adjr][adjc] == '1')
                    {
                        int nodeno = row * m + col;
                        int adjnodeno = adjr * m + adjc;

                        if (ds.find_Parent(nodeno) != ds.find_Parent(adjnodeno))
                        {
                            cout << "Hello" << endl;
                            ds.unionBySize(nodeno, adjnodeno);
                        }
                    }
                }
            }
        }
    }
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                int number = i * m + j;
                if (ds.parent[number] == number)
                    answer += 1;
            }
        }
    }
    return answer;
}

int main()
{
    return 0;
}