/* Inversion count */

#include <bits/stdc++.h>
using namespace std;

void merge(long long arr[], long long temp[], int left, int mid, int right, long long int &answer)
{
    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            answer += (mid - i);
        }
    }

    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

void merge_Sort(long long arr[], long long  temp[], int left, int right, long long int &answer)
{
    int mid;
    if (right > left)
    {
        mid = (left + right) / 2;

        merge_Sort(arr, temp, left, mid, answer);
        merge_Sort(arr, temp, mid + 1, right, answer);

        merge(arr, temp, left, mid + 1, right, answer);
    }
}

long long int inversionCount(long long arr[], long long N)
{
    long long temp[N];
    long long int answer = 0;
    merge_Sort(arr, temp, 0, N - 1, answer);
    return answer;
}

int main()
{
    long long arr[] = {2, 4, 1, 3, 5};
    long long n = 5;

    cout<<inversionCount(arr, n)<<endl;

    return 0;
}