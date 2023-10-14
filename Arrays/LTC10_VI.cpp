//////// IMP
//////// Question number 1365.

#include <bits/stdc++.h>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    vector<int> ans;
    int count[101] = {0};
    for (int i = 0; i < nums.size(); i++)
    {
        count[nums[i]]++;
    }

    for (int i = 1; i < 101; i++)
    {
        count[i] += count[i - 1];
    }

    for (int k = 0; k < nums.size(); k++)
    {
        if (nums[k] == 0)
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(count[nums[k] - 1]);
        }
    }
    return ans;
}

vector<int> smallerNumbersThanCurrent(vector<int> &nums)
{
    unordered_map<int, int> mp;
    vector<int> snums = nums;
    sort(snums.begin(), snums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        pair<int, int> p = {snums[i], i};
        mp.insert(p);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = mp[nums[i]];
    }
    return nums;
}

int main()
{
    vector<int> question = {8, 1, 2, 2, 3};
    question = smallerNumbersThanCurrent(question);

    for (int i = 0; i < 5; i++)
    {
        cout << question[i] << " ";
    }
    cout << endl;

    return 0;
}