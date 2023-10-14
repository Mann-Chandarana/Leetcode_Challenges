#include <bits/stdc++.h>
using namespace std;
/*--------  Hard --------*/

/*- Median of Two Sorted Arrays -*/

//////// Question number 2448.

#define ll long long
#define all(v) v.begin(), v.end()

/****** O(N) Solution ******/

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();

    int n = (n1 + n2);

    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int indexelement1 = -1, indexelement2 = -1;

    // apply the merge step:
    int i = 0, j = 0;
    while (i < n1 and j < n2)
    {
        if (nums1[i] < nums2[j])
        {
            if (cnt == ind1)
                indexelement1 = nums1[i];
            if (cnt == ind2)
                indexelement2 = nums1[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                indexelement1 = nums2[j];
            if (cnt == ind2)
                indexelement2 = nums2[j];
            cnt++;
            j++;
        }
    }
    while (i < n1)
    {
        if (cnt == ind1)
            indexelement1 = nums1[i];
        if (cnt == ind2)
            indexelement2 = nums1[i];
        cnt++;
        i++;
    }

    while (j < n2)
    {
        if (cnt == ind1)
            indexelement1 = nums2[j];
        if (cnt == ind2)
            indexelement2 = nums2[j];
        cnt++;
        j++;
    }
    if ((n & 1))
        return (double)indexelement2;
    else
        return (double)((double)(indexelement1 + indexelement2)) / 2.0;
}

/****** O(Logn) Solution ******/

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();

    if (n1 > n2)
        return findMedianSortedArrays(nums2, nums1);

    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;

    int n = n1 + n2;

    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1)
            r1 = nums1[mid1];

        if (mid2 < n2)
            r2 = nums2[mid2];

        if (mid1 - 1 >= 0)
            l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = nums2[mid2 - 1];

        if (l1 <= r2 and l2 <= r1)
        {
            if (n % 2 == 1)
                return max(l1, l2);
            return (double)((max(l1, l2) + min(r1, r2)) / 2.0);
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}

int main()
{
    return 0;
}