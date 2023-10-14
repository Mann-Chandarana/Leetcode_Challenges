/*--------Medium-----------*/

/*- Remove Nth Node From End of List -*/

//////// Question number 19.

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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head;
    ListNode *slow = head;

    for (int i = 1; i < n; i++)
    {
        fast = fast->next;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *gaya = slow->next;
    slow->next = slow->next->next;
    delete (gaya);

    return head;
}

int main()
{
    return 0;
}