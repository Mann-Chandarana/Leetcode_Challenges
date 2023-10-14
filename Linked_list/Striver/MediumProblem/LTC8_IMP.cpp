/*--------Medium-----------*/

/*- Delete the Middle Node of a Linked List -*/

//////// Question number 2095.

#include <bits/stdc++.h>
using namespace std;

/* Important concept of add one node at the start of the list */

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

ListNode *middleNode(ListNode *head)
{
    ListNode *fast = head, *slow = head;

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;

        if (fast->next != NULL)
            fast = fast->next;
    }
    return slow;
}

ListNode *deleteMiddle(ListNode *head)
{
    if (!head->next)
        return NULL;

    ListNode *slow = new ListNode(0);
    ListNode *fast = slow;

    slow->next = head;
    fast->next = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = slow->next->next;
    return head;
}

int main()
{
    return 0;
}