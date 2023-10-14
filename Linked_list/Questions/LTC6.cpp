/*--------Medium-----------*/

/*- Partition List -*/

//////// Question number 86.

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

ListNode *partition(ListNode *head, int x)
{
    ListNode *lessHead = new ListNode(-1);
    ListNode *lessTail = lessHead;

    ListNode *greaterHead = new ListNode(-1);
    ListNode *greaterTail = greaterHead;

    ListNode *current = head;

    while (current != NULL)
    {
        if (current->val < x)
        {
            lessTail->next = current;
            lessTail = lessTail->next;
        }
        else
        {
            greaterTail->next = current;
            greaterTail = greaterTail->next;
        }
        current = current->next;
    }
    greaterTail->next = NULL;
    lessTail->next = greaterHead->next;

    return lessHead->next;
}

int main()
{
    return 0;
}