/* 1337. The K Weakest Rows in a Matrix */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#define pii pair<int, int>

/**** Approach -1) Without using minheap ****/

int binarySearch(vector<int> &row)
{
    int n = row.size();

    int low = 0, high = n - 1;

    int ans;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (row[mid] == 1)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return low;
}

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    int n = mat.size();
    vector<int> answer;

    // index, count
    vector<pii> vec;

    for (int i = 0; i < n; i++)
    {
        int index = binarySearch(mat[i]);
        vec.push_back({i, index + 1});
    }

    sort(all(vec), [](pii &a, pii &b)
         {
        if(a.second==b.second)
           return a.first<b.first;
        
        return a.second<b.second; });

    for (int i = 0; i < k; i++)
        answer.push_back(vec[i].first);

    return answer;
}

/**** Approach -2) Using minheap ****/

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    int n = mat.size();
    vector<int> answer;

    auto compare = [](pii &a, pii &b)
    {
        if (a.second == b.second)
            return a.first < b.first;

        return a.second < b.second;
    };

    // index, count

    /* Catch:-
    We can also use max heap
     */
    priority_queue<pii, vector<pii>, decltype(compare)> pq(compare);

    for (int i = 0; i < n; i++)
    {
        int index = binarySearch(mat[i]);

        pq.push({i, index + 1});

        if (pq.size() > k)
            pq.pop();
    }

    while (!pq.empty())
    {
        answer.push_back(pq.top().first);
        pq.pop();
    }

    reverse(all(answer));
    return answer;
}

int main()
{
    return 0;
}