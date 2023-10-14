/*--------Medium-----------*/

/*- Hand of Straights -*/

//////// Question number 846.

#include <bits/stdc++.h>
using namespace std;

/* Using ordered map */

bool isNStraightHand(vector<int> &hand, int groupSize)
{
    if (groupSize == 1)
        return true;

    if (hand.size() % groupSize != 0)
        return false;

    map<int, int> mp;

    for (auto element : hand)
        mp[element]++;

    int i = 0;
    int first_number = (*mp.begin()).first;
    mp[first_number]--;
    if (mp[first_number] == 0)
        mp.erase(first_number);

    while (!mp.empty())
    {
        if (i >= groupSize - 1)
        {
            i = 0;
            first_number = (*mp.begin()).first;
            mp[first_number]--;
            if (mp[first_number] == 0)
                mp.erase(first_number);
        }
        else if (mp.find(first_number + 1) == mp.end())
            return false;
        else
        {
            i++;
            first_number = first_number + 1;
            mp[first_number]--;
            if (mp[first_number] == 0)
                mp.erase(first_number);
        }
    }
    return true;
}

/* Using Unordered map + heaps */

bool isNStraightHand(vector<int> &hand, int groupSize)
{

    if (hand.size() % groupSize != 0)
        return false;

    unordered_map<int, int> map;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto x : hand)
    {
        map[x]++;
    }

    for (auto p : map)
    {
        pq.push(p.first);
    }

    while (!pq.empty())
    {
        int val = pq.top();
        for (int i = 0; i < groupSize; i++)
        {
            if (map.find(i + val) == map.end())
                return false;

            map[i + val]--;
            if (map[i + val] == 0)
            {
                if (i + val != pq.top())
                    return false;
                pq.pop();
            }
        }
    }
    return true;
}

int main()
{
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    cout << isNStraightHand(hand, 3) << endl;
    return 0;
}