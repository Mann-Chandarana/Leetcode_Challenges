/***** insertion sort  ******/


#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int val = arr[i], j = i - 1;
        while (j >= 0 and arr[j] > val)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        arr[j + 1] = val;
    }
}

int main()
{
    int arr[] = {4, 1, 3, 9, 7};
    insertionSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}