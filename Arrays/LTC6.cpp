//////// Question number 1672.

#include <bits/stdc++.h>
using namespace std;

int maximumWealth(vector<vector<int>> &accounts)
{
    int richest = 0;
    for (auto &customer : accounts)
        richest = max(richest, accumulate(customer.begin(), customer.end(), 0));

    return richest;
}

// int maximumWealth(vector<vector<int>> &accounts)
// {
//     int n = accounts.size();
//     int m = accounts[0].size();

//     int sum , max_sum = INT_MIN;

//     for (int i = 0; i < n; i++)
//     {
//         sum = 0;
//         for (int j = 0; j < m; j++)
//         {
//             sum += accounts[i][j];
//         }
//         max_sum = max(max_sum, sum);
//     }
//     return max_sum;
// }

int main()
{
    vector<vector<int>> vec = {{1, 2, 3}, {3, 2, 1}};
    cout << maximumWealth(vec) << endl;

    return 0;
}