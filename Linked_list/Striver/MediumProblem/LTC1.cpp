/*- Middle of the linked list -*/

//////// Question number 876.

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

int main()
{
    return 0;
}