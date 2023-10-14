/*--------  Medium --------*/

/*- Minimum Time to Complete Trips -*/

//////// Question number 2187.

#include <bits/stdc++.h>
using namespace std;

/* Will give TLE */

long long minimumTime(vector<int> &time, int totalTrips)
{
    int ti = 1;
    while (totalTrips >= 0)
    {
        int answer = 0;
        for (int i = 0; i < time.size(); i++)
            answer += ti / time[i];

        if (answer == totalTrips)
            return ti;

        ti++;
    }
    return ti;
}

/* Using Binary Search */

bool Check_if_suital(vector<int> &time, int k, int &totalTrips)
{
    int answer = 0;
    for (int i = 0; i < time.size(); i++)
    {
        answer += k / time[i];
    }
    if (answer >= totalTrips)
        return true;

    return false;
}

long long minimumTime(vector<int> &time, int totalTrips)
{
    int n = time.size();
    long long mini = ((long long)*min_element(begin(time), end(time)));

    int l = 1, r = totalTrips * mini;
    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (Check_if_suital(time, mid, totalTrips))
            r = mid;

        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    vector<int> time = {1, 2, 3};
    cout << minimumTime(time, 5) << endl;
    return 0;
}