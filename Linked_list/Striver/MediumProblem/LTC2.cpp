/*- Reverse Linked List -*/

//////// Question number 206.

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        this->val = x;
        next = NULL;
    }

    ~ListNode()
    {
        if (next != NULL)
            next = NULL;
    }
};

/* Iterative solution */

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL, *curr = head, *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

/* Recursive solution */

ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main()
{
    return 0;
}