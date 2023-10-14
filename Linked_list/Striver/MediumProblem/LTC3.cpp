/*- Linked List Cycle -*/

//////// Question number 141.

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

bool hasCycle(ListNode *head)
{
    if(head==NULL)
    {
        return false;
    }
    ListNode *fast = head, *slow = head;

    while (fast != NULL and fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return true;
    }
    return false;
}

int main()
{
    return 0;
}