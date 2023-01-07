/* 944. Delete Columns to Make Sorted */

#include <bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string> &strs)
{
    int delet = 0;
    for (int i = 0; i < strs[0].size(); i++)
    {
        for (int j = 1; j < strs.size(); j++)
        {
            if (strs[j - 1][i] > strs[j][i])
            {
                delet++;
                break;
            }
        }
    }
    return delet;
}

int main()
{
    vector<string> strs = {"abc", "bce", "cae"};
    cout << minDeletionSize(strs) << endl;
    return 0;
}