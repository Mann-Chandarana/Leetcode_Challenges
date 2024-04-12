/** 2073. Time Needed to Buy Tickets **/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()

/** Approach - 1 **/

int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int n = tickets.size();
    queue<int> q;

    for (int i = 0; i < n; i++)
        q.push(i);

    int time = 0;

    while (!q.empty())
    {
        time++;

        int front = q.front();
        q.pop();

        tickets[front]--;

        if (k == front and tickets[front] == 0)
            return time;

        if (tickets[front] != 0)
            q.push(front);
    }
    return time;
}

/** Approach - 2 **/

int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int answer = 0;

    for (int i = 0; i < tickets.size(); i++)
    {
        if (i <= k)
            answer += min(tickets[i], tickets[k]);

        else
            answer += min(tickets[i], tickets[k] - 1);
    }
    return answer;
}

/** Approach - 3 **/

int timeRequiredToBuy(vector<int> &tickets, int k)
{
    int n = tickets.size(), answer = 0;

    while (tickets[k] > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (tickets[i] != 0)
                tickets[i]--, answer++;

            if (tickets[k] == 0)
                return answer;
        }
    }
    return answer;
}

int main()
{
    return 0;
}