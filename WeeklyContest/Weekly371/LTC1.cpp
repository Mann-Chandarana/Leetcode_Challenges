/* 100120. Maximum Strong Pair XOR I */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int maximumStrongPairXor(vector<int> &nums)
{
    int n = nums.size();

    int xori = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int a = nums[i], b = nums[j];

            if (abs(a - b) <= min(a, b))
                xori = max(xori, a ^ b);
        }
    }
    return xori;
}

int main()
{
    return 0;
}