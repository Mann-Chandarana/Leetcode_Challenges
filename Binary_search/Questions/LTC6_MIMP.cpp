/*--------  Medium --------*/

/*- Capacity To Ship Packages Within D Days -*/

//////// Question number 1011.

#include <bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int> &weights, int days)
{
    int sum = 0, maxi = INT_MIN;
    for (auto element : weights)
    {
        maxi = max(maxi, element);
        sum += element;
    }
    /* Here the maxi is the left element */
    /* Here the sum is the right element */
    
    while (maxi < sum)
    {
        int mid = maxi + (sum - maxi) / 2;

        int current_weight = 0, day_needed = 1;
        for (auto ele : weights)
        {
            if (current_weight + ele > mid)
            {
                day_needed++;
                current_weight = 0;
            }
            current_weight += ele;
        }
        if (day_needed > days)
            maxi = mid + 1;
        else
            sum = mid;
    }
    return maxi;
}

int main()
{
    return 0;
}