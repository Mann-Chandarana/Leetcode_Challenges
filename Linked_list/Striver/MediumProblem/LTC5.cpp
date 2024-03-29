/*- Palindrome Linked List -*/

//////// Question number 234.

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

ListNode *reverseList(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *p = NULL, *c = head, *n = head->next;
    while (c != NULL)
    {
        c->next = p;
        p = c;
        c = n;
        if (n != NULL)
            n = n->next;
    }
    return p;
}

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverseList(slow->next);
    ListNode *start = head, *mid = slow->next;
    while (mid != NULL)
    {
        if (mid->val != start->val)
            return false;
        start = start->next;
        mid = mid->next;
    }
    slow->next = reverseList(slow->next);
    return true;
}

int main()
{
    return 0;
}