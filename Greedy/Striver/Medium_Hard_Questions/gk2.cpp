/* Job Scheduling */

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

bool compare(Job A, Job B)
{
    return A.profit > B.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    int jobs = 0;

    sort(arr, arr + n, compare);
    int answer = 0, count = 0;
    vector<bool> deadline(n, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j >= 1; j--)
        {
            if (!deadline[j])
            {
                answer += arr[i].profit;
                count++;
                deadline[j] = true;
                break;
            }
        }
    }

    return {count, answer};
}

int main()
{
    Job A;
    A.id = 1;
    A.dead = 4;
    A.profit = 50;

    Job B;
    B.id = 2;
    B.dead = 1;
    B.profit = 60;

    Job arr[] = {A, B};
    vector<int> answer = JobScheduling(arr, 2);

    return 0;
}