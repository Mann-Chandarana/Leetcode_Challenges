/*--------Hard-----------*/

/*- Merge k Sorted Lists -*/

//////// Question number 23.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/********** Using Heaps **********/

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<int, vector<int>, greater<int>> pq; // Minheap

    for (auto element : lists)
    {
        while (element != NULL)
        {
            pq.push(element->val);
            element = element->next;
        }
    }

    ListNode *Head = new ListNode;

    if (!pq.empty())
        Head->val = pq.top(), pq.pop();

    else
        return NULL;

    ListNode *dummy = Head;

    while (!pq.empty())
    {
        dummy->next = new ListNode(pq.top());
        pq.pop();
        dummy = dummy->next;
    }
    return Head;
}

/********** Using merge sort **********/

ListNode *mergeKLists(vector<ListNode *> &lists, int start, int end)
{
    if (start > end)
        return NULL;

    if (start == end)
        return lists[start];

    int mid = start + (end - start) / 2;

    ListNode *left = mergeKLists(lists, start, mid);
    ListNode *right = mergeKLists(lists, mid + 1, end);

    return Merge(left, right);
}

ListNode *Merge(ListNode *left, ListNode *right)
{

    ListNode *dummy1 = left, *dummy2 = right, *dummy;
    ListNode *Head = new ListNode(-1);
    dummy = Head;
    while (dummy1 != NULL and dummy2 != NULL)
    {
        if (dummy1->val <= dummy2->val)
        {
            dummy->next = dummy1;
            dummy1 = dummy1->next;
        }
        else
        {
            dummy->next = dummy2;
            dummy2 = dummy2->next;
        }
        dummy = dummy->next;
    }
    dummy->next = dummy1 != NULL ? dummy1 : dummy2;
    return Head->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return NULL;
    return mergeKLists(lists, 0, lists.size() - 1);
}

int main()
{

    return 0;
}