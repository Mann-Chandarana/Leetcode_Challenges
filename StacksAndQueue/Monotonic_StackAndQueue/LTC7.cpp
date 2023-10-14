/*--------  Hard --------*/

/*- Trapping Rain Water -*/

//////// Question number 42

#include <bits/stdc++.h>
using namespace std;

/* Approach - 1 */

int trap(vector<int> &height)
{
    int n = height.size();

    int left = 0, right = n - 1, left_Max = INT_MIN, right_Max = INT_MIN;
    int answer = 0;

    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= left_Max)
                left_Max = height[left];

            else
                answer += left_Max - height[left];
            left++;
        }
        else
        {
            if (height[right] >= right_Max)
                right_Max = height[right];
            else
                answer += right_Max - height[right];

            right--;
        }
    }
    return answer;
}

/* Approach -2 */

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> suffix(n), prefix(n);

    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, height[i]);
        prefix[i] = maxi;
    }
    maxi = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        maxi = max(maxi, height[i]);
        suffix[i] = maxi;
    }

    int answer = 0;

    for (int i = 0; i < n; i++)
        answer += min(prefix[i], suffix[i]) - height[i];

    return answer;
}

int main()
{
    vector<int> height = {4, 2, 0, 3, 2, 5};
    cout << trap(height) << endl;
    return 0;
}