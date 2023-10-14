///// Important question
/*--------Medium-----------*/

/*- H-Index -*/

//////// Question number 274.

#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int> &citations)
{
    int n = citations.size();
    int low = 0, high = n - 1, mid;
    sort(citations.begin(), citations.end());

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (citations[mid] == n - mid)
        {
            return citations[mid];
        }
        else if (citations[mid] > n - mid)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return n - low;
}

int main()
{
    vector<int> ct = {3, 0, 6, 1, 5};
    cout << hIndex(ct) << endl;
    return 0;
}