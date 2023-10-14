/*--------Medium-----------*/

/*- Sort List -*/

//////// Question number 148.

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int x)
    {
        this->data = x;
        this->next = NULL;
    }
    ListNode()
    {
        this->data = -1;
        this->next = NULL;
    }
};

ListNode *findmid(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
ListNode *merge(ListNode *left, ListNode *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    ListNode *anshead = new ListNode(-1);
    ListNode *mptr = anshead;
    while (left && right)
    {
        if (left->val <= right->val)
        {
            mptr->next = left;
            mptr = left;
            left = left->next;
        }
        else
        {
            mptr->next = right;
            mptr = right;
            right = right->next;
        }
    }
    if (left)
    {
        mptr->next = left;
    }
    if (right)
    {
        mptr->next = right;
    }
    return anshead->next;
}
ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *mid = findmid(head);
    ListNode *left = head;
    ListNode *right = mid->next;
    mid->next = NULL;

    left = sortList(left);
    right = sortList(right);

    ListNode *mergeLL = merge(left, right);
    return mergeLL;
}

int main()
{
    return 0;
}