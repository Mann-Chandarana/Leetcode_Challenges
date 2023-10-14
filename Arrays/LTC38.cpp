//////// Question number 1122.

#include <bits/stdc++.h>
using namespace std;

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> answer;
    map<int, int> mp;

    for (int i = 0; i < arr1.size(); i++)
    {
        mp[arr1[i]]++;
    }
    for (auto element : arr2)
    {
        while (mp[element] != 0)
        {
            answer.push_back(element);
            mp[element]--;
        }
        if (mp[element] == 0)
        {
            mp.erase(element);
        }
    }

    for (auto element : mp)
    {
        while (element.second != 0)
        {
            answer.push_back(element.first);
            element.second--;
        }
    }
    return answer;
}

int main()
{
    vector<int> arr1 = {28,6,22,8,44,17};
    vector<int> arr2 = {22,28,8,6};
    arr1 = relativeSortArray(arr1, arr2);

    for (auto element : arr1)
    {
        cout << element << " ";
    }

    return 0;
}