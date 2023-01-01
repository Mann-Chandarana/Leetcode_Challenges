// Reverse an array :- geeks for geekss

#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    if (start < end)
    {
        swap(arr[start], arr[end]);
        reverseArray(arr, start + 1, end - 1);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    reverseArray(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}