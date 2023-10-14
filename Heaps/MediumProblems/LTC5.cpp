// Replace elements by its rank in the array

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

/* Storing index and arr[i] in minheap and then assigning rank to them  */

vector<int> replaceWithRank(vector<int> &arr, int N)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int i = 0; i < N; i++)
        pq.push({arr[i], i});

    int k = 1;

    while (!pq.empty())
    {
        int index = pq.top().second;
        pq.pop();
        arr[index] = k++;
    }

    return arr;
}

int main()
{
    return 0;
}