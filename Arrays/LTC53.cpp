/*--------Medium-----------*/

/*- Reduce the size of the array to half -*/

//////// Question number 1338.

#include <bits/stdc++.h>
using namespace std;

int minSetSize(vector<int> &arr)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    priority_queue<int> pq;

    for (auto element : mp)
    {
        pq.push(element.second);
    }

    int total = 0, count = 0;
    for (int i = 0; i < pq.size(); i++)
    {
        total += pq.top();
        pq.pop();
        count++;
        if (total >= arr.size() / 2)
        {
            break;
        }
    }
    return count;
}

int main()
{
    vector<int> arr = {3,3,3,3,5,5,5,2,2,7};
    cout << minSetSize(arr) << endl;
    
    return 0;
}
