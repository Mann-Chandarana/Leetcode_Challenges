/*--------Hard-----------*/

/*- Reverse Pairs -*/

//////// Question number 493.

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high, int &answer)
{
    int i = low, j = mid + 1;

    vector<int> final_array(high - low + 1);

    while (i <= mid and j <= high)
    {
        if (nums[i] > (long long)nums[j]*2)
        {
            answer += (mid - i + 1);
            j++;
        }
        else
        {
            i++;
        }
    }

    i = low, j = mid + 1;

    int k = 0;

    while (i <= mid and j <= high)
    {
        if (nums[i] <= nums[j])
        {
            final_array[k++] = nums[i++];
        }
        else
        {
            final_array[k++] = nums[j++];
        }
    }

    while (i <= mid)
    {
        final_array[k++] = nums[i++];
    }

    while (j <= high)
    {
        final_array[k++] = nums[j++];
    }
    k = 0;
    for (int i = low; i <= high; i++)
    {
        nums[i] = final_array[k++];
    }
}

void mergeSort(vector<int> &nums, int low, int high, int &answer)
{
    if (low < high)
    {
        int mid = low + ((high - low) / 2);
        cout<<"Mid is "<<mid<<endl;
        mergeSort(nums, low, mid, answer);
        mergeSort(nums, mid + 1, high, answer);

        merge(nums, low, mid, high, answer);
    }
}

int reversePairs(vector<int> &nums)
{
    int answer = 0;

    mergeSort(nums, 0, nums.size() - 1, answer);

    return answer;
}

int main()
{
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << reversePairs(nums) << endl;
    return 0;
}