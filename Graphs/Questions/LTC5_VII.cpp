/*--------  Medium --------*/

/*- Snakes and Ladders -*/

//////// Question number 909.

#include <bits/stdc++.h>
using namespace std;

/**** Using Breadth first search ****/

pair<int, int> findCoordinates(int currVal, int n)
{
    int row = n - (currVal - 1) / n - 1;
    int col = (currVal - 1) % n;
    if (row % 2 == n % 2)
    {
        return {row, n - 1 - col};
    }
    else
    {
        return {row, col};
    }
}

int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    int moves = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            int curr = q.front();
            q.pop();

            if (curr == n * n)
                return moves;

            for (int j = 1; j <= 6; j++)
            {
                if (curr + j > n * n)
                    break;

                pair<int, int> p = findCoordinates(curr + j, n);
                int row = p.first;
                int col = p.second;

                if (!visited[row][col])
                {
                    visited[row][col] = true;

                    if (board[row][col] == -1)
                    {
                        q.push(curr + j);
                    }
                    else
                    {
                        q.push(board[row][col]);
                    }
                }
            }
        }   
        moves++;
    }

    return -1;
}

int main()
{

    return 0;
}