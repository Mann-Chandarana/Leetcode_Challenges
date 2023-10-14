#include <bits/stdc++.h>
using namespace std;

int FilledBuckets(int N, vector<int> queries)
{
    int buckets_filled = 0;
    bool even_filled = false, odd_filled = false;
    for (auto element : queries)
    {
        if (element == 1)
        {
            buckets_filled = N;
            even_filled = true;
            odd_filled = true;
        }

        else if (element == 2)
        {
            if (buckets_filled == 0)
                continue;
            if (even_filled)
            {
                buckets_filled -= (N / 2);
                even_filled = false;
            }
        }
        else if (element == 3)
        {
             if (buckets_filled == 0) continue;
            if (odd_filled)
            {
                buckets_filled -= (N - N / 2);
                odd_filled = false;
            }
        }

        else if (element == 4)
        {
            buckets_filled = 0;
        }
    }
    return buckets_filled;
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> queries(m);

    for (int i = 0; i < m; i++)
        cin >> queries[i];

    cout << FilledBuckets(n, queries) << endl;

    return 0;
}