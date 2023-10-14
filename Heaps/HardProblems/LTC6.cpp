/*--------Hard-----------*/

/*- Find Median from Data Stream -*/

//////// Question number 295.

#include <bits/stdc++.h>
using namespace std;

/* Intution we have to keep the top element of queue to the top only when new element come */

class MedianFinder
{
    priority_queue<int, vector<int>, greater<int>> min_pq;
    priority_queue<int> max_pq;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (max_pq.empty() || max_pq.top() > num)
            max_pq.push(num);
        else
            min_pq.push(num);

        if (max_pq.size() > min_pq.size() + 1)
            min_pq.push(max_pq.top()), max_pq.pop();
        else if (min_pq.size() > max_pq.size() + 1)
            max_pq.push(min_pq.top()), min_pq.pop();
    }

    double findMedian()
    {
        if (max_pq.size() > min_pq.size())
            return max_pq.top();

        else if (min_pq.size() > max_pq.size())
            return min_pq.top();

        else
            return (max_pq.top() + min_pq.top()) / 2.0;
    }
};

int main()
{
    return 0;
}