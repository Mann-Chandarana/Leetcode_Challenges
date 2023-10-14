/*-------- Medium -----------*/

/*- Maximum Bags With Full Capacity of Rocks -*/

//////// Question number 2279.

#include <bits/stdc++.h>
using namespace std;

int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
{
    for (int i = 0; i < capacity.size(); i++)
    {
        capacity[i] = capacity[i] - rocks[i];
    }

    sort(capacity.begin(), capacity.end());

    int answer = 0;

    for (int i = 0; i < capacity.size(); i++)
    {
        if (capacity[i] == 0)
        {
            answer++;
            continue;
        }
        if (additionalRocks >= capacity[i])
        {
            answer++;
            additionalRocks -= capacity[i];
        }
    }
    return answer;
}

int main()
{
    vector<int> capacaity = {10,2,2}, rocks = {2,2,0};
    cout << maximumBags(capacaity, rocks, 110) << endl;
    return 0;
}