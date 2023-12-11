/* 1287. Element Appearing More Than 25% In Sorted Array */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/////////////// Approach -1)

int firstOccur(int target, int l, int r, vector<int> &arr)
{

    int result = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target)
        {
            result = mid;
            r = mid - 1;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return result;
}

int lastOccur(int target, int l, int r, vector<int> &arr)
{

    int result = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == target)
        {
            result = mid;
            l = mid + 1;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return result;
}

int findSpecialInteger(vector<int> &arr)
{
    int n = arr.size();

    int freq = n / 4;

    vector<int> candidates{arr[n / 4], arr[n / 2], arr[3 * n / 4]};

    for (int &candidate : candidates)
    {

        int left = firstOccur(candidate, 0, n - 1, arr);
        int right = lastOccur(candidate, 0, n - 1, arr);

        if (right - left + 1 > freq)
        {
            return candidate;
        }
    }

    return -1;
}

/////////////// Approach -2)

int findSpecialInteger(vector<int> &arr)
{
    int n = arr.size();
    int freq = n / 4;

    for (int i = 0; i < n - freq; i++)
    {
        if (arr[i] == arr[i + freq])
            return arr[i];
    }
    return -1;
}

/////////////// Approach -3)

int findSpecialInteger(vector<int> &arr)
{
    double n = arr.size(), count = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] == arr[i])
            count++;
        else
        {
            double percentage = ((count / n) * 100);
            if (percentage > 25)
                return arr[i - 1];
            count = 1;
        }
    }
    double percentage = ((count / n) * 100);
    if (percentage > 25)
        return arr[n - 1];

    return -1;
}

int main()
{
    return 0;
}