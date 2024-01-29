/*-------- Medium --------*/

/*- Out of Boundary Paths -*/

//////// Question number 576.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef pair<int, int> pii;

const ll mod = 1e9 + 7;

/***** Recursion + Memorization  *****/

vector<pii> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

ll solve(int i, int j, int maxMove, int m, int n, vector<vector<vector<ll>>> &dp)
{
    if (i >= m || j >= n || i < 0 || j < 0)
        return 1;

    if (maxMove <= 0)
        return 0;

    if (dp[i][j][maxMove] != -1)
        return dp[i][j][maxMove];

    ll answer = 0;

    for (auto &element : direction)
        answer += solve(i + element.first, j + element.second, maxMove - 1, m, n, dp) % mod;

    return dp[i][j][maxMove] = answer % mod;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(maxMove + 1, -1)));

    return solve(startRow, startColumn, maxMove, m, n, dp);
}

/***** Tabulation  *****/

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    vector<vector<vector<ll>>> dp(m + 1, vector<vector<ll>>(n + 1, vector<ll>(maxMove + 1, 0)));
    for (int move = 1; move <= maxMove; move++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (auto &dir : direction)
                {
                    int x = i + dir.first, y = j + dir.second;

                    if (x >= m || x < 0 || y >= n || y < 0)
                        dp[i][j][move] = (dp[i][j][move] + 1) % mod;
                    else
                        dp[i][j][move] = (dp[i][j][move] + dp[x][y][move - 1]) % mod;
                }
            }
        }
    }

    return dp[startRow][startColumn][maxMove];
}

int main()
{
    cout << findPaths(1, 3, 3, 0, 1) << endl;
    return 0;
}