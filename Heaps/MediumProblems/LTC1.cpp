/*--------Medium-----------*/

/*- Kth Largest Element in an Array -*/

//////// Question number 1834.


// Time complexity :- O(nlogk)

#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; // Minheap
    for (int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}

int main()
{

    return 0;
}