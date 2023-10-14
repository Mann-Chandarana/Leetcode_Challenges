/* 160. Intersection of Two Linked Lists */

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


int length(ListNode *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

/* First appraoch */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
        return NULL;

    // step1
    int lenA = length(headA), lenB = length(headB);

    // step2
    if (lenA > lenB)
    {
        while (lenA > lenB)
        {
            headA = headA->next;
            lenA--;
        }
    }
    else if (lenA < lenB)
    {
        while (lenA < lenB)
        {
            headB = headB->next;
            lenB--;
        }
    }

    // step 3
    while (headA && headB)
    {
        if (headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

/* Second approach */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // getting the tail
    ListNode *tail = headA;
    while (tail->next)
    {
        tail = tail->next;
    }

    // creating a loop
    tail->next = headA;

    // detecting and finding the intersection
    ListNode *fast = headB, *slow = headB;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = headB;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            // undoing the loop
            tail->next = NULL;
            return slow;
        };
    }
    tail->next = NULL;
    return NULL;
}

int main()
{
    return 0;
}