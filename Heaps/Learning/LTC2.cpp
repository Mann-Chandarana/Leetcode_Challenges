#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &arr, int N, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < N and arr[l] > arr[largest])
        largest = l;

    if (r < N and arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, N, largest);
    }
}

void convertMinToMaxHeap(vector<int> &arr, int N)
{
    for (int i = (N / 2) - 1; i >= 0; i--)
    {
        maxHeapify(arr, N, i);
    }
}

int main()
{
    return 0;
}