/****** Count number of subarray with given xor k  ********/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> A, int k)
{
    int c = 0, count = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < A.size(); i++)
    {
        c ^= A[i];

        if (c == k)
        {
            count++;
        }
        int h = c ^ k;

        if (mp.find(h) != mp.end())
        {
            count += mp[h];
        }
        mp[c]++;
    }
    return count;
}

int main()
{
    vector<int> A = {5, 6, 7, 8, 9};
    cout << solve(A, 5) << endl;
    return 0;
}