/*-------- Medium --------*/

/*- Convert an Array Into a 2D Array With Conditions -*/

//////// Question number 2610.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#define vpii vector<pair<int, int>>
#define vppi vector<pair<pair<int, int>, int>>
#define umps unordered_map<string, vector<string>>

unordered_map<int, vector<int>> mp;
unordered_set<int> st;

/** Approach -1) **/

vector<vector<int>> findMatrix(vector<int> &nums)
{
    vector<vector<int>> answer;
    int total_array = 0, n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (st.find(nums[i]) == st.end())
        {
            if (answer.size() == 0)
            {
                vector<int> temp;
                temp.push_back(nums[i]);
                answer.push_back(temp);
            }
            else
                answer[0].push_back(nums[i]);

            st.insert(nums[i]);
            mp[nums[i]].push_back(0);
        }
        else
        {
            vector<int> temp = mp[nums[i]];
            int n = answer.size();

            if (temp.size() == n)
            {
                vector<int> temp1;
                temp1.push_back(nums[i]);
                answer.push_back(temp1);
                total_array++;
                mp[nums[i]].push_back(total_array);
            }
            else
            {
                int j = 0;
                for (auto element : temp)
                {
                    if (j != element)
                        break;

                    j++;
                }
                answer[j].push_back(nums[i]);
                mp[nums[i]].push_back(j);
            }
        }
    }
    return answer;
}

/** Appraoch -2) **/

vector<vector<int>> findMatrix(vector<int> &nums)
{
    int n = nums.size();

    unordered_map<int, int> mp;

    vector<vector<int>> result;

    for (int i = 0; i < n; i++)
    {
        int freq = mp[nums[i]];

        if (freq == result.size())
            result.push_back({});

        result[freq].push_back(nums[i]);
        mp[nums[i]]++;
    }

    return result;
}

int main()
{
    return 0;
}