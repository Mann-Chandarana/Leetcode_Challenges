/*--------  Medium --------*/

/*- High-Access Employees -*/

//////// Question number 100128.

#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back

vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
{
    unordered_map<string, vector<string>> mp;
    vector<string> ans;

    for (auto &i : access_times)
        mp[i[0]].pb(i[1]);

    for (auto &item : mp)
    {
        vector<string> vstr = item.second;
        if (vstr.size() >= 3)
        {
            sort(vstr.begin(),vstr.end());

            for (int i = 0; i < vstr.size() - 2; i++)
            {
                if ((stoi(vstr[i + 2]) - stoi(vstr[i])) < 100)
                {
                    ans.pb(item.first);
                    break;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<string>> access_times = {{"akuhmu", "0454"}, {"aywtqh", "0523"}, {"akuhmu", "0518"}, {"ihhkc", "0439"}, {"ihhkc", "0508"}, {"akuhmu", "0529"}, {"aywtqh", "0530"}, {"aywtqh", "0419"}};
    vs answer = findHighAccessEmployees(access_times);

    for (auto element : answer)
        cout << element << " ";
    cout << endl;
    return 0;
}