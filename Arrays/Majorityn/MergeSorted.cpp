#include <bits/stdc++.h>
using namespace std;

/* Optimal solution */

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int j = n - 1, i = m - 1, k = m + n - 1;

    while (i >= 0 and j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0)
        nums1[k--] = nums2[j--];
}

/* Optimal solution */

void merge(vector<int> &arr1, int m, vector<int> &arr2, int n)
{
    int left = n - 1;
    int right = 0;

    // Swap the elements until arr1[left] is
    //  smaller than arr2[right]:
    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else
        {
            break;
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.begin());
}

int main()
{
    return 0;
}