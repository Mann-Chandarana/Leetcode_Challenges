/*--------Medium-----------*/

/*- Seat allocation problem -*/

//////// Question number 1386.

#include <bits/stdc++.h>
using namespace std;

bool vacant(int start, int end, vector<int> reservedSeats)
{
    for (int seat : reservedSeats)
    {
        if (seat >= start and seat <= end)
        {
            return false;
        }
    }
    return true;
}

int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
{
    unordered_map<int, vector<int>> seats;

    for (auto reservedSeat : reservedSeats)
    {
        if (reservedSeat[1] == 1 or reservedSeat[1] == 10)
        {
            continue;
        }
        seats[reservedSeat[0]].push_back(reservedSeat[1]);
    }

    int families = (n - seats.size()) * 2;

    for (auto seat : seats)
    {
        if (vacant(2, 5, seat.second) || vacant(4, 7, seat.second) | vacant(6, 9, seat.second))
        {
            families++;
        }
    }
    return families;
}

int main()
{
    vector<vector<int>> reservedSeats = {{2, 1}, {1, 8}, {2, 6}};
    cout << maxNumberOfFamilies(2, reservedSeats) << endl;
    return 0;
}