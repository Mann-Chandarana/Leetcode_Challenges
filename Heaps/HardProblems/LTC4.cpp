/*- Kth Largest Element in a Stream -*/

//////// Question number 703.

#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (auto element : nums)
        {
            pq.push(element);
            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val)
    {
        pq.push(val);

        if (pq.size() > k)
            pq.pop();

        return pq.top();
    }
};

int main()
{
    return 0;
}