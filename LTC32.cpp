/*-------- Medium --------*/

/*- Furthest Building You Can Reach -*/

//////// Question number 1642.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{
    int n = heights.size();
    priority_queue<int, vector<int>, greater<int>> pq;

    int i = 0;

    for (i = 0; i < n - 1; i++)
    {
        int difference = heights[i + 1] - heights[i];

        if (difference > 0)
        {
            if (pq.size() < ladders)
                pq.push(difference);
            else
            {
                if (!pq.empty() and difference > pq.top())
                {
                    if (bricks >= pq.top())
                        bricks -= pq.top(), pq.pop(), pq.push(difference);
                    else
                        break;
                }
                else
                {
                    if (bricks >= difference)
                        bricks -= difference;
                    else
                        break;
                }
            }
        }
    }
    return i;
}

int main()
{
    vector<int> heights = {14, 3, 19, 3};
    cout << furthestBuilding(heights, 17, 0) << endl;
    return 0;
}