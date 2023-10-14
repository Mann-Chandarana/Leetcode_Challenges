#include <bits/stdc++.h>
using namespace std;

double findSmallestMaxDist(vector<int> &s, int K)
{
    int n = s.size(), c;
    double lo = 0, hi = s[n - 1] - s[0];
    while (hi - lo > 1e-6)
    {
        double mid = lo + (hi - lo) / 2;
        c = 0;
        for (int i = 0; i < n - 1; i++)
            c += (int)((s[i + 1] - s[i]) / mid);
        if (c > K)
            lo = mid;
        else
            hi = mid;
    }
    return hi;
    // Code here
}

int main()
{
    return 0;
}