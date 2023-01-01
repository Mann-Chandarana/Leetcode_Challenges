// Frequencies of Limited Range Array Elements :- geeks for geekss

#include <bits/stdc++.h>
using namespace std;

void frequencyCount(vector<int> &arr, int N, int P)
{
    vector<int> freq(N + 1, 0);

    for (int i = 0; i <= N; i++)
    {
        if (arr[i] <= N)
        {
            freq[arr[i]]++;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        arr[i - 1] = freq[i];
    }
}

int main()
{
    vector<int> arr = {2, 3, 2, 3, 5};
    frequencyCount(arr, 5, 5);
    return 0;
}