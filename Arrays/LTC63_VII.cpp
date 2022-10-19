///// Important question
/*--------Medium-----------*/

/*- Task schedular -*/

//////// Question number 621.

#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return a >= b ? a : b;
}
int leastInterval(vector<char> &tasks, int n)
{
    vector<int> freq(26, 0);

    for (int i = 0; i < tasks.size(); i++)
    {
        freq[tasks[i] - 'A']++;
    }

    int max_count = *max_element(freq.begin(), freq.end());

    int count = (max_count - 1) * (n + 1);
    cout << count << endl;

    for (int i = 0; i < freq.size(); i++)
    {
        if (freq[i] == max_count)
        {
            count++;
        }
    }
    count = max(count, tasks.size());

    return count;
}

// int leastInterval(vector<char> &tasks, int k)
// {
//     unordered_map<char, int> hash;
//     for (int i = 0; i < tasks.size(); i++)
//         hash[tasks[i]]++;

//     priority_queue<int> pq; // max queue

//     for (auto it : hash)
//         pq.push(it.second);

//     int timer = 0;

//     while (!pq.empty())
//     {
//         vector<int> temp;
//         for (int i = 0; i <= k; i++)
//         {
//             if (!pq.empty())
//             {
//                 temp.push_back(pq.top()); // pick frequently occuring tasks (greedy)
//                 pq.pop();
//             }
//         }

//         for (int i = 0; i < temp.size(); i++)
//         {
//             if (--temp[i] > 0)
//                 pq.push(temp[i]);
//             // (if tasks of the kind remain push them back in)
//         }

//         timer += pq.empty() ? temp.size() : k + 1; // if queue is empty then we got no remaining tasks hence the current block size
//                                                    // is temp.size() else we got a block of size k+1
//     }
//     return timer;
// }

int main()
{
    vector<char> tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', 'B'};
    cout << leastInterval(tasks, 2) << endl;
    return 0;
}