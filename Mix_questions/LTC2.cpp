/*-------- Hard -----------*/

/*- IPO  -*/

//////// Question number 502.

#include <bits/stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    int n = profits.size();
    vector<pair<int, int>> project(n);

    for (int i = 0; i < n; i++)
    {
        project[i] = {capital[i], profits[i]};
    }
    sort(project.begin(), project.end());
    priority_queue<int> pq;
    int i = 0;
    while (k--)
    {
        while (i < n and project[i].first <= w)
        {
            pq.push(project[i].second);
            i++;
        }
        if (pq.empty())
            break;

        w += pq.top();
        pq.pop();
    }
    return w;
}

int main()
{
    vector<int> profits = {1, 2, 3}, capital = {0, 1, 1};

    cout << findMaximizedCapital(2, 0, profits, capital) << endl;
    return 0;
}