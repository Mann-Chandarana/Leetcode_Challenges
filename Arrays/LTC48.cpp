/*--------Medium-----------*/

//////// Question number 48.

#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (i < j)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
}

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    transpose(matrix);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m / 2; j++)
        {
            swap(matrix[i][j], matrix[i][m - j - 1]);
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    rotate(matrix);

    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}