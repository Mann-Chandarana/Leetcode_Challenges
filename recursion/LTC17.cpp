/*-------- Hard -----------*/

/*- N-Queens -*/

//////// Question number 51.

#include <bits/stdc++.h>
using namespace std;

/* Using valid function */

bool isFeasible(int row, int col, vector<string> board, int n)
{
    int duprow = row, dupcol = col;

    while (row >= 0 and col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;

        row--;
        col--;
    }

    row = duprow;
    col = dupcol;

    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;

        col--;
    }

    row = duprow;
    col = dupcol;

    while (row < n and col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;

        row++;
        col--;
    }

    return true;
}

void solve(int col, int n, vector<vector<string>> &answer, vector<string> &board)
{
    if (col == n)
    {
        answer.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isFeasible(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, n, answer, board);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> answer;
    vector<string> board(n);
    string s(n, '.');

    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    solve(0, n, answer,board);

    return answer;
}

/* Using Hashing */

void solve(int col, int n, vector<vector<string>> &answer, vector<string> &board, vector<int> left_row, vector<int> upperDiagonal, vector<int> lowerDiagonal)
{
    if (col == n)
    {
        answer.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (left_row[row] == 0 and upperDiagonal[row + col] == 0 and lowerDiagonal[n - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            left_row[row] = 1;
            upperDiagonal[row + col] = 1;
            lowerDiagonal[n - 1 + col - row] = 1;
            solve(col + 1, n, answer, board, left_row, upperDiagonal, lowerDiagonal);
            board[row][col]='.';
            left_row[row] = 0;
            upperDiagonal[row + col] = 0;
            lowerDiagonal[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> answer;
    vector<string> board(n);
    string s(n, '.');

    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    vector<int> left_row(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);

    solve(0, n, answer, board, left_row, upperDiagonal, lowerDiagonal);

    return answer;
}

int main()
{
    return 0;
}