/*-------- Hard --------*/

/*- Meeting Rooms III -*/

//////// Question number 2402.

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pli;

#define ll long long
#define all(v) v.begin(), v.end()

/************* Approach -1) *************/

int mostBooked(int n, vector<vector<int>> &meetings)
{
    sort(all(meetings));

    vector<ll> lastAvailable(n, 0);
    vector<ll> roomsUsedCount(n, 0);

    for (auto element : meetings)
    {
        int start = element[0];
        int end = element[1];
        int duration = end - start;
        bool found = false;

        ll earlyEndRoomTime = LLONG_MAX;
        int earlyEndRoom = 0;

        for (int room = 0; room < n; room++)
        {
            if (lastAvailable[room] <= start)
            {
                lastAvailable[room] = end;
                roomsUsedCount[room]++;
                found = true;
                break;
            }

            if (lastAvailable[room] < earlyEndRoomTime)
                earlyEndRoomTime = lastAvailable[room], earlyEndRoom = room;
        }
        if (!found)
        {
            lastAvailable[earlyEndRoom] += duration;
            roomsUsedCount[earlyEndRoom]++;
        }
    }

    int maxi = -1, ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (roomsUsedCount[i] > maxi)
            ans = i, maxi = roomsUsedCount[i];
    }
    return ans;
}

/************* Approach -2) *************/

int mostBooked(int n, vector<vector<int>> &meetings)
{
    int m = meetings.size();

    sort(all(meetings));

    vector<int> roomsUsedCount(n, 0);

    priority_queue<pli, vector<pli>, greater<pli>> usedRooms;
    priority_queue<int, vector<int>, greater<int>> ununsedRooms;

    for (int room = 0; room < n; room++)
        ununsedRooms.push(room);

    for (auto &meet : meetings)
    {
        int start = meet[0];
        int end = meet[1];

        while (!usedRooms.empty() and usedRooms.top().first <= start)
        {
            int room = usedRooms.top().second;
            usedRooms.pop();
            ununsedRooms.push(room);
        }

        if (!ununsedRooms.empty())
        {
            int room = ununsedRooms.top();
            ununsedRooms.pop();
            usedRooms.push({end, room});
            roomsUsedCount[room]++;
        }
        else
        {
            int room = usedRooms.top().second;
            ll endTime = usedRooms.top().first;
            usedRooms.pop();

            usedRooms.push({endTime + (end - start), room});
            roomsUsedCount[room]++;
        }
    }

    int resultRoom = -1;
    int maxUse = 0;

    for (int room = 0; room < n; room++)
    {
        if (roomsUsedCount[room] > maxUse)
        {
            resultRoom = room;
            maxUse = roomsUsedCount[room];
        }
    }

    return resultRoom;
}

int main()
{
    vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
    cout << mostBooked(2, meetings) << endl;
    return 0;
}