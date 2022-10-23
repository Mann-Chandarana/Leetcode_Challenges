///// Important question

/*--------Medium-----------*/

/*- Minimum Rounds to Complete All Tasks -*/

//////// Question number 2244.

#include <bits/stdc++.h>
using namespace std;

int minimumRounds(vector<int> &tasks)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < tasks.size(); i++)
    {
        mp[tasks[i]]++;
    }

    int count = 0;

    for (auto element : mp)
    {
        if (element.second < 2)
        {
            return -1;
        }

        else if (element.second % 3 == 0)
        {
            count += (element.second / 3);
        }

        else
        {
            count += (element.second) / 3 + 1;
        }
    }
    return count;
}

int main()
{
    return 0;
}