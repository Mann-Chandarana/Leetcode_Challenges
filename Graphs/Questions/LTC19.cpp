/*--------  Hard --------*/

/*- Reconstruct Itinerary -*/

//////// Question number 332.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#define vpii vector<pair<int, int>>
#define vppi vector<pair<pair<int, int>, int>>
#define umps unordered_map<string, vector<string>>

int numTicket = 0;
vector<string> answer;

bool dfs(umps &mp, string fromAirpot, vector<string> &path)
{
    path.push_back(fromAirpot);
    if (path.size() == numTicket + 1)
    {
        answer = path;
        return true;
    }

    vector<string> &neighbour = mp[fromAirpot];

    for (int i = 0; i < neighbour.size(); i++)
    {
        string toAirpot = neighbour[i];
        neighbour.erase(neighbour.begin() + i);

        if (dfs(mp, toAirpot, path))
            return true;

        neighbour.insert(neighbour.begin() + i, toAirpot);
    }
    path.pop_back();
    return false;
}

vector<string> findItinerary(vector<vector<string>> &tickets)
{
    numTicket = tickets.size();
    umps mp;

    for (auto &element : tickets)
    {
        mp[element[0]].push_back(element[1]);
    }

    vector<string> path;

    for (auto &element : mp)
        sort(all(element.second));

    dfs(mp, "JFK", path);

    return answer;
}

int main()
{
    return 0;
}