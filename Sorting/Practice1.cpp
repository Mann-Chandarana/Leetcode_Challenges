/***** Selection sort  ******/

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_idx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            swap(arr[min_idx], arr[i]);
        }
    }
}

int main()
{
    int arr[] = {3, 1, 4, 7, 9};
    selectionSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}