/* 6440. Difference of Number of Distinct Values on Diagonals */

#include <bits/stdc++.h>
using namespace std;

int top_left(int x, int y, vector<vector<int>> &grid, unordered_set<int> st)
{
    int i = x - 1, j = y - 1;

    while (i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size())
        st.insert(grid[i--][j--]);


    return st.size();
}

int bottom_right(int x, int y, vector<vector<int>> &grid, unordered_set<int> st)
{
    int i = x + 1, j = y + 1;

    while (i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size())
        st.insert(grid[i++][j++]);

    return st.size();
}

vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> answer(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            unordered_set<int> st;
            int answer1 = top_left(i, j, grid, st);
            int answer2 = bottom_right(i, j, grid, st);
            answer[i][j] = abs(answer1 - answer2);
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> grid = {{1}};
    grid = differenceOfDistinctValues(grid);

    for (auto element : grid)
    {
        for (auto x : element)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}