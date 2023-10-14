#include <bits/stdc++.h>
using namespace std;

bool find_char(vector<vector<char>> board, int i, int j, string word, int k)
{
    cout << k << endl;
    static bool answer;
    if (k == word.length())
    {
        return true;
    }
    if (i + 1 < board.size() and board[i + 1][j] == word[k])
    {
        cout << "Hello" << endl;
        answer = find_char(board, i + 1, j, word, k++);
    }
    else if (i - 1 >= 0 and board[i - 1][j] == word[k])
    {
        cout << "Hi" << endl;
        answer = find_char(board, i - 1, j, word, k++);
    }
    else if (j + 1 < board[0].size() and board[i][j + 1] == word[k])
    {
        cout << "He" << endl;
        answer = find_char(board, i, j + 1, word, k++);
    }
    else if (j - 1 >= 0 and board[i][j - 1] == word[k])
    {
        cout << "Hel" << endl;
        answer = find_char(board, i, j - 1, word, k++);
    }
    else
    {
        answer = false;
    }
    return answer;
}

bool find_word(string word, vector<vector<char>> board, int k)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == word[k])
            {
                cout << word[k] << " ";
                if (find_char(board, i, j, word, k++))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    vector<string> answer;
    for (auto w : words)
    {
        if (find_word(w, board, 0))
        {
            answer.push_back(w);
        }
    }
    return answer;
}

int main()
{
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                  {'e', 't', 'a', 'e'},
                                  {'i', 'h', 'k', 'r'},
                                  {'i', 'f', 'l', 'v'}};

    vector<string> words = {"oath", "pea", "eat", "rain"};

    words = findWords(board, words);

    for (auto element : words)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}