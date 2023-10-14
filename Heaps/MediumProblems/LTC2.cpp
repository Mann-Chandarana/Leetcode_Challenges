/* Kth smallest element in an array */

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq;

    for (int i = l; i < r; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}

int main()
{
    int arr[] = {7, 10, 4, 20, 15};
    cout << kthSmallest(arr, 0, 5, 4) << endl;
    return 0;
}