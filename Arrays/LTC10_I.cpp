//////// IMP
//////// Question number 1365.

#include <bits/stdc++.h>
using namespace std;

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