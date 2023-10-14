/* Longest Subarray with sum K */

#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(int A[], int N, int K)
{
    unordered_map<int, int> mp;
    int presum = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        presum = presum + A[i];
        if (presum == K)
        {
            cnt = i + 1;
        }
        if (mp.find(presum) == mp.end())
        {
            mp.insert({presum, i});
        }
        if (mp.find(presum - K) != mp.end())
        {
            cnt = max(cnt, i - mp[presum - K]);
        }
    }
    return cnt;
}

int main()
{
    return 0;
}