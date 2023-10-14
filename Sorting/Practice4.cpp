/***** Merge sort  ******/

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int low = l, high = m+1;
    int k = 0;
    int arr1[r - l + 1];

    while (low <= m and high <= r)
    {
        if (arr[low] < arr[high])
        {
            arr1[k++] = arr[low++];
        }
        else
        {
            arr1[k++] = arr[high++];
        }
    }

    while (low <= m)
    {
        arr1[k++] = arr[low++];
    }

    while (high <= r)
    {
        arr1[k++] = arr[high++];
    }

    k = 0;
    for (int i = l; i <= r; i++)
    {
        arr[i] = arr1[k++];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + ((r - l) / 2);
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int arr[] = {10 ,9, 8, 7, 6, 5 ,4 ,3 ,2, 1};
    int n = (sizeof(arr) / sizeof(int));
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}