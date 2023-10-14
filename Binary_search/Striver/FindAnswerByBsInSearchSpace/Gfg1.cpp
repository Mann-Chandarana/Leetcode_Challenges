/* Find Nth root of M */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int NthRoot(int n, int m)
{
    ll s = 0, e = m;

    while (s <= e)
    {
        ll mid = s + ((e - s) / 2);

        if (pow(mid, n) == m)
            return mid;
        else if (pow(mid, n) > m)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

int main()
{
    cout << NthRoot(6, 4096) << endl;
    return 0;
}