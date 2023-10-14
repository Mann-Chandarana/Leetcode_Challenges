/* Geeks for Geeks :- Immediate Smaller Element */

#include <bits/stdc++.h>
using namespace std;

void immediateSmaller(vector<int> &arr, int n)
{
    int element = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
            element = arr[i], arr[i] = -1;

        if (element < arr[i])
        {
            int temp = arr[i];
            arr[i] = element;
            element = temp;
        }
        else
            element = arr[i], arr[i] = -1;
    }
}

int main()
{
    return 0;
}