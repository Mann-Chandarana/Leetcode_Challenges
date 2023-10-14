// Count all the subsequence with sum k :- geeks for geekss

#include <bits/stdc++.h>
using namespace std;

int findWays(int arr[], int n, int target, int index)
{
    if (index == n)
    {
        if (target == 0)
        {
            return 1;
        }
        return 0;
    }

    int left = findWays(arr, n, target - arr[index], index + 1);
    int right = findWays(arr, n, target, index + 1);

    return left + right;
}

int perfectSum(int arr[], int n, int sum)
{
    return findWays(arr, n,sum,0);
}

int main()
{
    return 0;
}