/* Geeks for Geeks :- N meeting in one room */

#include <bits/stdc++.h>
using namespace std;

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++)
        vec.push_back({end[i], start[i]});

    sort(vec.begin(), vec.end());

    int count = 1, ending = vec[0].first;

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i].second >= ending)
            ending = vec[i].first, count++;
    }

    return count;
}

int main()
{
    int start[] = {1, 3, 0, 5, 8, 5}, end[] = {2, 4, 6, 7, 9, 9};
    return 0;
}