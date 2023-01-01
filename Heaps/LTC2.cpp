/*--------Medium-----------*/

/*- Single-Threaded CPU -*/

//////// Question number 1834.

#include <bits/stdc++.h>
using namespace std;

vector<int> getOrder(vector<vector<int>> &tasks)
{
    int n = tasks.size();
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        tasks[i].push_back(i);
    }
    sort(tasks.begin(), tasks.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    long long start = tasks[0][0];
    vector<int> answer;
    int i = 0;
    while (!pq.empty() or i < n)
    {
        while (i < n and start >= tasks[i][0])
        {
            pq.push({tasks[i][1], tasks[i][2]});
            i++;
        }

        if (pq.empty())
        {
            start = tasks[i][0];
        }
        else
        {
            start += pq.top().first;
            answer.push_back(pq.top().second);
            pq.pop();
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> tasks = {{7,10},{7,12},{7,5},{7,4},{7,2}};
    vector<int> answer;
    answer = getOrder(tasks);

    for (auto element : answer)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}