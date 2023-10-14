/*-------- Medium -----------*/

/*- Linked List Cycle II -*/

//////// Question number 142.

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

ListNode *detectCycle(ListNode *head)
{
    if (head == NULL)
        return head;

    ListNode *fast = head, *slow = head;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
}

int main()
{
    return 0;
}