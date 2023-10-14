/*--------  Medium --------*/

/*- Minimum Moves to Spread Stones Over Grid -*/

//////// Question number 2850.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpii vector<pair<int, int>>
#define vppi vector<pair<pair<int, int>, int>>

/*********** Approach -1) ***********/

void solve(int i, int count, vpii &zero, vppi &extra, int &answer)
{
    if (i >= zero.size())
    {
        answer = min(answer, count);
        return;
    }

    for (int k = 0; k < extra.size(); k++)
    {
        if (extra[k].second == 0)
            continue;
        extra[k].second--;
        solve(i + 1, count + (abs(extra[k].first.first - zero[i].first) + abs(extra[k].first.second - zero[i].second)), zero, extra,answer);
        extra[k].second++;
    }
}

int minimumMoves(vector<vector<int>> &grid)
{
    vpii zero;
    vppi extra;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == 0)
                zero.push_back({i, j});

            else if (grid[i][j] > 1)
                extra.push_back({{i, j}, grid[i][j] - 1});
        }
    }
    if (zero.size() == 0)
        return 0;
    int answer = INT_MAX;
    solve(0, 0, zero, extra, answer);
    return answer;
}

/*********** Approach -2) ***********/

int minimumMoves(vector<vector<int>> &grid)
{
    int t = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == 0)
                t++;
        }
    }
    if (t == 0)
        return 0;

    int ans = INT_MAX;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == 0)
            {
                for (int ni = 0; ni < 3; ni++)
                {
                    for (int nj = 0; nj < 3; nj++)
                    {
                        int d = abs(ni - i) + abs(nj - j);
                        if (grid[ni][nj] > 1)
                        {
                            grid[ni][nj]--;
                            grid[i][j]++;
                            ans = min(ans, d + minimumMoves(grid));
                            grid[ni][nj]++;
                            grid[i][j]--;
                        }
                    }
                }
            }
        }
    }

    return ans;
}

int main()
{
    return 0;
}