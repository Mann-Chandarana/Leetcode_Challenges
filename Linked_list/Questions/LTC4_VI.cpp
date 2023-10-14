/*--------Medium-----------*/

/*- Swap Nodes in Pairs -*/

//////// Question number 24.

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

/* Iterative approach */

ListNode *swapPairs(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    ListNode *prev = dummy, *curr = dummy->next;

    while (curr != NULL and curr->next != NULL)
    {
        prev->next = curr->next;
        curr->next = prev->next->next;
        prev->next->next = curr;

        prev = curr;
        curr = prev->next;
    }
    return dummy->next;
}

/* Recursive approach */

ListNode *swapPairs(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *newHead = head->next;
    head->next = swapPairs(head->next->next);
    newHead->next = head;

    return newHead;
}

int main()
{
    return 0;
}