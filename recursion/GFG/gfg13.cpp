// Rat in maze :- geeks for geekss

#include <bits/stdc++.h>
using namespace std;

/*********** Short form ***********/

string dir = "DLRU";

void solve(vector<vector<int>> m, int n, int i, int j, string ans, vector<string> &answer, vector<vector<bool>> &visited, int di[], int dj[])
{
    if (i == n - 1 and j == n - 1)
    {
        answer.push_back(ans);
        return;
    }

    for (int z = 0; z < 4; z++)
    {
        int nexti = i + di[z], nextj = j + dj[z];
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !visited[nexti][nextj] && m[nexti][nextj] == 1)
        {
            ans.push_back(dir[z]);
            visited[nexti][nextj] = 1;
            solve(m, n, nexti, nextj, ans, answer, visited, di, dj);
            visited[nexti][nextj] = 0;
            ans.pop_back();
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> answer;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    if (m[0][0] == 1)
    {
        visited[0][0] = true;
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};

        solve(m, n, 0, 0, "", answer, visited, di, dj);
    }

    return answer;
}

/*********** Long form ***********/

bool isSafe(int i, int j, int n, vector<vector<bool>> visited, vector<vector<int>> m)
{
    if (i < 0 or j < 0 or i >= n or j >= n or visited[i][j] == true or m[i][j] == 0)
    {
        return false;
    }
    return true;
}

void solve(vector<vector<int>> m, int n, int i, int j, string ans, vector<string> &answer, vector<vector<bool>> &visited)
{
    if (i == n - 1 and j == n - 1)
    {
        answer.push_back(ans);
        return;
    }

    // down
    if (isSafe(i + 1, j, n, visited, m))
    {
        ans.push_back('D');
        visited[i][j] = true;
        solve(m, n, i + 1, j, ans, answer, visited);
        visited[i][j] = false;
        ans.pop_back();
    }

    // up
    if (isSafe(i - 1, j, n, visited, m))
    {
        ans.push_back('U');
        visited[i][j] = true;
        solve(m, n, i - 1, j, ans, answer, visited);
        visited[i][j] = false;
        ans.pop_back();
    }

    // left
    if (isSafe(i, j - 1, n, visited, m))
    {
        ans.push_back('L');
        visited[i][j] = true;
        solve(m, n, i, j - 1, ans, answer, visited);
        visited[i][j] = false;
        ans.pop_back();
    }

    // right
    if (isSafe(i, j + 1, n, visited, m))
    {
        ans.push_back('R');
        visited[i][j] = true;
        solve(m, n, i, j + 1, ans, answer, visited);
        visited[i][j] = false;
        ans.pop_back();
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> answer;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;

    if (m[0][0] == 1)
    {
        solve(m, n, 0, 0, "", answer, visited);
    }

    return answer;
}

int main()
{
    return 0;
}