/* Maximum of all subarray of size k */

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &arr, int n, int k)
{
    // your code here
    deque<int> q;
    int i = 0, j = 0;
    vector<int> res;
    while (j < n)
    {
        while (!q.empty() and q.back() < arr[j])
        {
            q.pop_back();
        }
        q.push_back(arr[j]);

        if (j - i + 1 < k)
            j++;

        else if (j - i + 1 == k)
        {
            res.push_back(q.front());

            if (q.front() == arr[i])
            {
                q.pop_front();
            }
            i++, j++;
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {3, 2, -6, 1, 0};
    arr = maxSlidingWindow(arr, 5, 3);

    for (auto element : arr)
    {
        cout << element << " ";
    }

    return 0;
}