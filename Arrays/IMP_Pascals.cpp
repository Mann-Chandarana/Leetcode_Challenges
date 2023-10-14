/* Pascal's Triangle */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int nCr(int n, int r)
{
    long long res = 1;

    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void pascalTriangle(int n)
{
    long long ans = 1;

    for (int i = 0; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }
    cout << endl;
}

vector<ll> nthRowOfPascalTriangle(int n)
{
    ll ans = 1;
    vector<ll> answer;
    answer.push_back(1);
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        answer.push_back(ans);
    }
    return answer;
}

vector<vector<int>> PascalTriangle(int n)
{
    vector<vector<int>> ans;

    for (int row = 1; row <= n; row++)
    {
        vector<int> templist;
        for (int col = 1; col <= row; col++)
        {
            templist.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(templist);
    }
    return ans;
}

int main()
{
    return 0;
}