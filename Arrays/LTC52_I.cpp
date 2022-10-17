/*--------Medium-----------*/

/*- Sort matrix diagonally -*/

//////// Question number 1329.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
{
    //// Can also use priority queue instead of vector<int>
    
    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            mp[i - j].push_back(mat[i][j]);
        }
    }

    for (auto element : mp)
    {
        int k = element.first;
        sort(mp[k].begin(), mp[k].end());
    }

    for (int i = mat.size() - 1; i >= 0; i--)
    {
        for (int j = mat[0].size()-1; j >= 0; j--)
        {
            mat[i][j] = mp[i - j].back();
            mp[i - j].pop_back();
        }
    }

    return mat;
}

int main()
{
    return 0;
}