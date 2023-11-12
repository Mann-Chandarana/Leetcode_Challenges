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

    for (auto &i : mp)
    {
        vector<string> vec = i.second;
        if (vec.size() >= 3)
        {
            sort(all(vec));

            for (int i = 0; i < vec.size() - 2; i++)
            {
                if ((stoi(vec[i + 2]) - stoi(vec[i])) < 100)
                {
                    answer.pb(element.first);
                    break;
                }
            }
        }
    }
    return answer;
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