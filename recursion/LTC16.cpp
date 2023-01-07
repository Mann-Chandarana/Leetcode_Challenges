/*-------- Medium -----------*/

/*- Word Search -*/

//////// Question number 79.

#include <bits/stdc++.h>
using namespace std;

bool word_search(vector<vector<char>> &board, string word, int i, int j, int n, int m, int k)
{
    if (k == word.length())
    {
        return true;
    }

    if (i < 0 || i >= n || j < 0 || j >= m || word[k] != board[i][j] || board[i][j] == '.')
    {
        return false;
    }

    board[i][j] = '.';
    bool temp = false;

    int x[4] = {0, 0, -1, 1};
    int y[4] = {-1, 1, 0, 0};

    for (int idx = 0; idx < 4; idx++)
    {
        temp = temp || word_search(board, word, i + x[idx], j + y[idx], n, m, k + 1);
    }
    board[i][j] = word[k];

    return temp;
}
bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    if (n == 0 || word.size() == 0)
    {
        return false;
    }

    int m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (word_search(board, word, i, j, n, m, 0))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {{'a', 'a'}};
    cout << exist(board, "aaa") << endl;
    return 0;
}