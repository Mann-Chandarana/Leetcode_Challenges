/*--------Hard-----------*/

/*- Koko Eating Bananas -*/

//////// Question number 875.

#include <bits/stdc++.h>
using namespace std;

bool isValid(int mid, vector<int> piles, int h)
{
    int hours = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        hours += piles[i] / mid;
        piles[i] = piles[i] % mid;

        if (piles[i] > 0)
            hours++;
        if (hours > h)
            return false;
    }
    return true;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int sum = accumulate(piles.begin(), piles.end(), 0);

    int start = 1, end = *max_element(piles.begin(), piles.end());
    int ans = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isValid(mid, piles, h))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    cout << minEatingSpeed(piles, 8) << endl;
    return 0;
}