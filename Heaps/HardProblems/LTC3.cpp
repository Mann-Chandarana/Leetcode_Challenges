/*--------Medium-----------*/

/*- Top K Frequent Elements -*/

//////// Question number 347.

#include <bits/stdc++.h>
using namespace std;

/*
 Using Minheap
 Time complexity :- O(NlogK)
*/

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vec;

    for (auto element : nums)
        mp[element]++;

    for (auto element : mp)
    {
        pq.push({element.second, element.first});

        if (pq.size() > k)
            pq.pop();
    }

    while (!pq.empty())
    {
        vec.push_back(pq.top().second);
        pq.pop();
    }

    return vec;
}


/*
 Using Maxheap
 Time complexity :- O(NlogN)
*/

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>> pq; /// Max heap
    vector<int> vec;

    for (auto element : nums)
        mp[element]++;

    for (auto element : mp)
        pq.push({element.second, element.first});

    while (!pq.empty() and k--)
    {
        vec.push_back(pq.top().second);
        pq.pop();
    }
}

int main()
{
    return 0;
}